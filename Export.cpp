//
// Copyright (c) 2012, Wei Mingzhi <whistler_wmz@users.sf.net>.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program;  if not, see <http://www.gnu.org/licenses/>.
//

#include "Main.h"

#define BOT_PAKFILE_PREFIX	"zeta"

#define COPYRIGHT_MESSAGE	"Doom3 Hook DLL Prototype (C) 2012, Wei Mingzhi"

idSys *						sys = NULL;
idCommon *					common = NULL;
idCmdSystem *				cmdSystem = NULL;
idCVarSystem *				cvarSystem = NULL;
idFileSystem *				fileSystem = NULL;
idNetworkSystem *			networkSystem = NULL;
idRenderSystem *			renderSystem = NULL;
idSoundSystem *				soundSystem = NULL;
idRenderModelManager *		renderModelManager = NULL;
idUserInterfaceManager *	uiManager = NULL;
idDeclManager *				declManager = NULL;
idAASFileManager *			AASFileManager = NULL;
idCollisionModelManager *	collisionModelManager = NULL;

idRenderWorld *				gameRenderWorld = NULL;		// all drawing is done to this world
idSoundWorld *				gameSoundWorld = NULL;		// all audio goes to this world

idGame *					game;

gameExport_t				gameExport;

static int					gameDLL;
static GetGameAPI_t			pfnGetGameAPI;

idCVar *					idCVar::staticVars = NULL;

/*
==============
Sys_ListFiles
==============
*/
#ifdef _WIN32

int Sys_ListFiles( const char *directory, const char *extension, idStrList &list ) {
	char		search[ MAX_OSPATH ];
	struct _finddata_t findinfo;
	int			findhandle;
	int			flag;

	if ( !extension) {
		extension = "";
	}

	// passing a slash as extension will find directories
	if ( extension[0] == '/' && extension[1] == 0 ) {
		extension = "";
		flag = 0;
	} else {
		flag = _A_SUBDIR;
	}

	sprintf( search, "%s\\*%s", directory, extension );

	// search
	list.Clear();

	findhandle = _findfirst( search, &findinfo );
	if ( findhandle == -1 ) {
		return -1;
	}

	do {
		if ( flag ^ ( findinfo.attrib & _A_SUBDIR ) ) {
			list.Append( findinfo.name );
		}
	} while ( _findnext( findhandle, &findinfo ) != -1 );

	_findclose( findhandle );

	return list.Num();
}

#else

int Sys_ListFiles( const char *directory, const char *extension, idStrList &list ) {
	struct dirent *d;
	DIR *fdir;
	bool dironly = false;
	char search[ MAX_OSPATH ];
	struct stat st;
	bool debug;

	list.Clear();

	debug = cvarSystem->GetCVarBool( "fs_debug" );

	if (!extension)
		extension = "";

	// passing a slash as extension will find directories
	if (extension[0] == '/' && extension[1] == 0) {
		extension = "";
		dironly = true;
	}

	// search
	// NOTE: case sensitivity of directory path can screw us up here
	if ((fdir = opendir(directory)) == NULL) {
		if (debug) {
			common->Printf("Sys_ListFiles: opendir %s failed\n", directory);
		}
		return -1;
	}

	while ((d = readdir(fdir)) != NULL) {
		idStr::snPrintf(search, sizeof(search), "%s/%s", directory, d->d_name);
		if (stat(search, &st) == -1)
			continue;
		if (!dironly) {
			idStr look(search);
			idStr ext;
			look.ExtractFileExtension(ext);
			if (extension[0] != '\0' && ext.Icmp(&extension[1]) != 0) {
				continue;
			}
		}
		if ((dironly && !(st.st_mode & S_IFDIR)) ||
			(!dironly && (st.st_mode & S_IFDIR)))
			continue;

		list.Append(d->d_name);
	}

	closedir(fdir);

	if ( debug ) {
		common->Printf( "Sys_ListFiles: %d entries in %s\n", list.Num(), directory );
	}

	return list.Num();
}

#endif

/*
=================
ExtractGameDLL
=================
*/
void ExtractGameDLL( void ) {
	idStrList list;
	int i;
	char dllName[ MAX_OSPATH ];

	sys->DLL_GetFileName( "game", dllName, MAX_OSPATH );

	// scan the directory for all pk4 files
	Sys_ListFiles( fileSystem->RelativePathToOSPath( ".", "fs_basepath" ), ".pk4", list );

	// sort the list by filename
	list.Sort();

	// walk through all pak files in reverse order
	for ( i = list.Num() - 1; i >= 0; --i ) {
		if ( list[ i ].Icmpn( BOT_PAKFILE_PREFIX, idStr::Length( BOT_PAKFILE_PREFIX ) ) == 0 ) {
			continue; // skip myself
		}

		unzFile uf;
		unz_file_info file_info;

		// open the pak file
		uf = unzOpen( fileSystem->RelativePathToOSPath( list[ i ].c_str(), "fs_basepath" ) );
		if ( !uf ) {
			continue;
		}

		// try to locate game DLL inside pak
		if ( unzLocateFile( uf, dllName, 0 ) != UNZ_OK ) {
			unzClose( uf );
			continue;
		}

		if ( unzGetCurrentFileInfo( uf, &file_info, dllName, sizeof( dllName ), NULL, 0, NULL, 0 ) != UNZ_OK ) {
			unzClose( uf );
			continue;
		}

		if ( unzOpenCurrentFile( uf ) != UNZ_OK ) {
			unzClose( uf );
			continue;
		}

		unsigned char *buf = new unsigned char[ file_info.uncompressed_size ];

		if ( !buf ) {
			unzCloseCurrentFile( uf );
			unzClose( uf );
			delete[] buf;
			continue;
		}

		// read the file to buffer
		if ( unzReadCurrentFile( uf, buf, file_info.uncompressed_size ) <= 0 ) {
			unzCloseCurrentFile( uf );
			unzClose( uf );
			delete[] buf;
			continue;
		}

		// extract the dll
		fileSystem->WriteFile( va( "dlls/%s", dllName ), buf, file_info.uncompressed_size );

		unzCloseCurrentFile( uf );
		unzClose( uf );
		delete[] buf;

		break;
	}
}

/*
=================
GetDLLPath
=================
*/
const char *GetDLLPath( void ) {
	char dllName[ MAX_OSPATH ];

	sys->DLL_GetFileName( "game", dllName, MAX_OSPATH );
	return fileSystem->RelativePathToOSPath( va( "dlls/%s", dllName ) );
}

/*
=================
LoadGameDLL
=================
*/
void LoadGameDLL( void ) {
	ExtractGameDLL();

	gameDLL = sys->DLL_Load( GetDLLPath() );
	if ( !gameDLL ) {
		common->FatalError( "couldn't load game dynamic library" );
		return;
	}

	pfnGetGameAPI = (GetGameAPI_t) sys->DLL_GetProcAddress( gameDLL, "GetGameAPI" );
	if ( !pfnGetGameAPI ) {
		sys->DLL_Unload( gameDLL );
		gameDLL = NULL;
		common->FatalError( "couldn't find game DLL API" );
		return;
	}
}

/*
=================
UnloadGameDLL
=================
*/
void UnloadGameDLL( void ) {
	if ( gameDLL ) {
		sys->DLL_Unload( gameDLL );
		gameDLL = NULL;
	}
	pfnGetGameAPI = NULL;
	game = NULL;
}

/*
===========
GetGameAPI
============
*/
#if __MWERKS__
#pragma export on
#endif
#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
extern "C" gameExport_t *GetGameAPI( gameImport_t *import ) {
#if __MWERKS__
#pragma export off
#endif

	if ( import->version == GAME_API_VERSION ) {
		// set interface pointers used by the game
		sys							= import->sys;
		common						= import->common;
		cmdSystem					= import->cmdSystem;
		cvarSystem					= import->cvarSystem;
		fileSystem					= import->fileSystem;
		networkSystem				= import->networkSystem;
		renderSystem				= import->renderSystem;
		soundSystem					= import->soundSystem;
		renderModelManager			= import->renderModelManager;
		uiManager					= import->uiManager;
		declManager					= import->declManager;
		AASFileManager				= import->AASFileManager;
		collisionModelManager		= import->collisionModelManager;
	}

	// load the actual game DLL
	LoadGameDLL();

	if ( !gameDLL ) {
		common->FatalError( "Unable to load game DLL" );
		return NULL;
	}

	// call game DLL's GetGameAPI()
	gameExport_t *gameExportDLL = pfnGetGameAPI(&importLocal);

	if ( !gameExportDLL ) {
		common->FatalError( "GetGameAPI() failed" );
		UnloadGameDLL();
		return NULL;
	}

	// set interface pointers used by idLib
	idLib::sys					= sys;
	idLib::common				= common;
	idLib::cvarSystem			= cvarSystem;
	idLib::fileSystem			= fileSystem;

	// save game API pointer
	game = gameExportDLL->game;

	// setup export interface
	gameExport.version = gameExportDLL->version;
	gameExport.game = (idGame *)&gameInterface;
	gameExport.gameEdit = gameExportDLL->gameEdit;

	common->Printf( "%s\n", COPYRIGHT_MESSAGE );

	return &gameExport;
}
#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif
