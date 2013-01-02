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

static idSysLocal						sysLocal;					// non-portable system services
static idCommonLocal					commonLocal;				// common
static idCmdSystemLocal					cmdSystemLocal;				// console command system
static idCVarSystemLocal				cvarSystemLocal;			// console variable system
static idFileSystemLocal				fileSystemLocal;			// file system
static idNetworkSystemLocal				networkSystemLocal;			// network system
static idRenderSystemLocal				renderSystemLocal;			// render system
static idSoundSystemLocal				soundSystemLocal;			// sound system
static idRenderModelManagerLocal		renderModelManagerLocal;	// render model manager
static idUserInterfaceManagerLocal		uiManagerLocal;				// user interface manager
static idDeclManagerLocal				declManagerLocal;			// declaration manager
static idAASFileManagerLocal			AASFileManagerLocal;		// AAS file manager
static idCollisionModelManagerLocal		collisionModelManagerLocal;	// collision model manager

gameImport_t importLocal = {
	GAME_API_VERSION,
	&sysLocal,
	&commonLocal,
	&cmdSystemLocal,
	&cvarSystemLocal,
	&fileSystemLocal,
	&networkSystemLocal,
	&renderSystemLocal,
	&soundSystemLocal,
	&renderModelManagerLocal,
	&uiManagerLocal,
	&declManagerLocal,
	&AASFileManagerLocal,
	&collisionModelManagerLocal
};

void idSysLocal::DebugPrintf( const char *fmt, ... ) {
	va_list argptr;

	va_start( argptr, fmt );
	sys->DebugVPrintf( fmt, argptr );
	va_end( argptr );
}

void idSysLocal::DebugVPrintf( const char *fmt, va_list arg ) {
	sys->DebugVPrintf( fmt, arg );
}

double idSysLocal::GetClockTicks( void ) {
	return sys->GetClockTicks();
}

double idSysLocal::ClockTicksPerSecond( void ) {
	return sys->ClockTicksPerSecond();
}

cpuid_t idSysLocal::GetProcessorId( void ) {
	return sys->GetProcessorId();
}

const char * idSysLocal::GetProcessorString( void ) {
	return sys->GetProcessorString();
}

const char * idSysLocal::FPU_GetState( void ) {
	return sys->FPU_GetState();
}

bool idSysLocal::FPU_StackIsEmpty( void ) {
	return sys->FPU_StackIsEmpty();
}

void idSysLocal::FPU_SetFTZ( bool enable ) {
	sys->FPU_SetFTZ( enable );
}

void idSysLocal::FPU_SetDAZ( bool enable ) {
	sys->FPU_SetDAZ( enable );
}

void idSysLocal::FPU_EnableExceptions( int exceptions ) {
	sys->FPU_EnableExceptions( exceptions );
}

bool idSysLocal::LockMemory( void *ptr, int bytes ) {
	return sys->LockMemory( ptr, bytes );
}

bool idSysLocal::UnlockMemory( void *ptr, int bytes ) {
	return sys->UnlockMemory( ptr, bytes );
}

void idSysLocal::GetCallStack( address_t *callStack, const int callStackSize ) {
	sys->GetCallStack( callStack, callStackSize );
}

const char * idSysLocal::GetCallStackStr( const address_t *callStack, const int callStackSize ) {
	return sys->GetCallStackStr( callStack, callStackSize );
}

const char * idSysLocal::GetCallStackCurStr( int depth ) {
	return sys->GetCallStackCurStr( depth );
}

void idSysLocal::ShutdownSymbols( void ) {
	sys->ShutdownSymbols();
}

int idSysLocal::DLL_Load( const char *dllName ) {
	return sys->DLL_Load( dllName );
}

void * idSysLocal::DLL_GetProcAddress( int dllHandle, const char *procName ) {
	return sys->DLL_GetProcAddress( dllHandle, procName );
}

void idSysLocal::DLL_Unload( int dllHandle ) {
	sys->DLL_Unload(dllHandle);
}

void idSysLocal::DLL_GetFileName( const char *baseName, char *dllName, int maxLength ) {
	sys->DLL_GetFileName( baseName, dllName, maxLength );
}

sysEvent_t idSysLocal::GenerateMouseButtonEvent( int button, bool down ) {
	return sys->GenerateMouseButtonEvent( button, down );
}

sysEvent_t idSysLocal::GenerateMouseMoveEvent( int deltax, int deltay ) {
	return sys->GenerateMouseMoveEvent( deltax, deltay );
}

void idSysLocal::OpenURL( const char *url, bool quit ) {
	sys->OpenURL( url, quit );
}

void idSysLocal::StartProcess( const char *exePath, bool quit ) {
	sys->StartProcess( exePath, quit );
}

void idCommonLocal::Init( int argc, const char **argv, const char *cmdline ) {
	common->Init( argc, argv, cmdline );
}

void idCommonLocal::Shutdown( void ) {
	common->Shutdown();
}

void idCommonLocal::Quit( void ) {
	common->Quit();
}

bool idCommonLocal::IsInitialized( void ) const {
	return common->IsInitialized();
}

void idCommonLocal::Frame( void ) {
	common->Frame();
}

void idCommonLocal::GUIFrame( bool execCmd, bool network ) {
	common->GUIFrame( execCmd, network );
}

void idCommonLocal::Async( void ) {
	common->Async();
}

void idCommonLocal::StartupVariable( const char *match, bool once ) {
	common->StartupVariable( match, once );
}

void idCommonLocal::InitTool( const toolFlag_t tool, const idDict *dict ) {
	common->InitTool( tool, dict );
}

void idCommonLocal::ActivateTool( bool active ) {
	common->ActivateTool( active );
}

void idCommonLocal::WriteConfigToFile( const char *filename ) {
	common->WriteConfigToFile( filename );
}

void idCommonLocal::WriteFlaggedCVarsToFile( const char *filename, int flags, const char *setCmd ) {
	common->WriteFlaggedCVarsToFile( filename, flags, setCmd );
}

void idCommonLocal::BeginRedirect( char *buffer, int buffersize, void (*flush)( const char * ) ) {
	common->BeginRedirect( buffer, buffersize, flush );
}

void idCommonLocal::EndRedirect( void ) {
	common->EndRedirect();
}

void idCommonLocal::SetRefreshOnPrint( bool set ) {
	common->SetRefreshOnPrint( set );
}

void idCommonLocal::Printf( const char *fmt, ... ) {
	va_list argptr;

	va_start( argptr, fmt );
	common->VPrintf( fmt, argptr );
	va_end( argptr );
}

void idCommonLocal::VPrintf( const char *fmt, va_list arg ) {
	common->VPrintf( fmt, arg );
}

void idCommonLocal::DPrintf( const char *fmt, ... ) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	common->DPrintf( buf );
}

void idCommonLocal::Warning( const char *fmt, ... ) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	common->Warning( buf );
}

void idCommonLocal::DWarning( const char *fmt, ...) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	common->DWarning( buf );
}

void idCommonLocal::PrintWarnings( void ) {
	common->PrintWarnings();
}

void idCommonLocal::ClearWarnings( const char *reason ) {
	common->ClearWarnings( reason );
}

void idCommonLocal::Error( const char *fmt, ... ) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	common->Error( buf );
}

void idCommonLocal::FatalError( const char *fmt, ... ) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	common->FatalError( buf );
}

const idLangDict * idCommonLocal::GetLanguageDict( void ) {
	return common->GetLanguageDict();
}

const char * idCommonLocal::KeysFromBinding( const char *bind ) {
	return common->KeysFromBinding( bind );
}

const char * idCommonLocal::BindingFromKey( const char *key ) {
	return common->BindingFromKey( key );
}

int idCommonLocal::ButtonState( int key ) {
	return common->ButtonState( key );
}

int idCommonLocal::KeyState( int key ) {
	return common->KeyState( key );
}

void idCmdSystemLocal::Init( void ) {
	return cmdSystem->Init();
}

void idCmdSystemLocal::Shutdown( void ) {
	return cmdSystem->Shutdown();
}

void idCmdSystemLocal::AddCommand( const char *cmdName, cmdFunction_t function, int flags, const char *description, argCompletion_t argCompletion ) {
	cmdSystem->AddCommand( cmdName, function, flags, description, argCompletion );
}

void idCmdSystemLocal::RemoveCommand( const char *cmdName ) {
	cmdSystem->RemoveCommand( cmdName );
}

void idCmdSystemLocal::RemoveFlaggedCommands( int flags ) {
	cmdSystem->RemoveFlaggedCommands( flags );
}

void idCmdSystemLocal::CommandCompletion( void(*callback)( const char *s ) ) {
	cmdSystem->CommandCompletion( callback );
}

void idCmdSystemLocal::ArgCompletion( const char *cmdString, void(*callback)( const char *s ) ) {
	cmdSystem->ArgCompletion( cmdString, callback );
}

void idCmdSystemLocal::BufferCommandText( cmdExecution_t exec, const char *text ) {
	cmdSystem->BufferCommandText( exec, text );
}

void idCmdSystemLocal::ExecuteCommandBuffer( void ) {
	cmdSystem->ExecuteCommandBuffer();
}

void idCmdSystemLocal::ArgCompletion_FolderExtension( const idCmdArgs &args, void(*callback)( const char *s ), const char *folder, bool stripFolder, ... ) {
	const char *param[16];
	const char *p;
	va_list argPtr;
	int i;

	memset( param, 0, sizeof( param ) );
	i = 0;

	va_start( argPtr, stripFolder );

	// This is an ugly hack, but it should work
	for ( p = va_arg( argPtr, const char * ); p && i < 16; p = va_arg( argPtr, const char * ), ++i ) {
		param[i] = p;
	}

	cmdSystem->ArgCompletion_FolderExtension( args, callback, folder, stripFolder,
		param[0], param[1], param[2], param[3], param[4], param[5], param[6],
		param[7], param[8], param[9], param[10], param[11], param[12], param[13],
		param[14], param[15], NULL );
}

void idCmdSystemLocal::ArgCompletion_DeclName( const idCmdArgs &args, void(*callback)( const char *s ), int type ) {
	cmdSystem->ArgCompletion_DeclName( args, callback, type );
}

void idCmdSystemLocal::BufferCommandArgs( cmdExecution_t exec, const idCmdArgs &args ) {
	cmdSystem->BufferCommandArgs( exec, args );
}

void idCmdSystemLocal::SetupReloadEngine( const idCmdArgs &args ) {
	cmdSystem->SetupReloadEngine( args );
}

bool idCmdSystemLocal::PostReloadEngine( void ) {
	return cmdSystem->PostReloadEngine();
}

void idCVarSystemLocal::Init( void ) {
	cvarSystem->Init();
}

void idCVarSystemLocal::Shutdown( void ) {
	cvarSystem->Shutdown();
}

bool idCVarSystemLocal::IsInitialized( void ) const {
	return cvarSystem->IsInitialized();
}

void idCVarSystemLocal::Register( idCVar *cvar ) {
	cvarSystem->Register( cvar );
}

idCVar * idCVarSystemLocal::Find( const char *name ) {
	return cvarSystem->Find( name );
}

void idCVarSystemLocal::SetCVarString( const char *name, const char *value, int flags ) {
	cvarSystem->SetCVarString( name, value, flags );
}

void idCVarSystemLocal::SetCVarBool( const char *name, const bool value, int flags ) {
	cvarSystem->SetCVarBool( name, value, flags );
}

void idCVarSystemLocal::SetCVarInteger( const char *name, const int value, int flags ) {
	cvarSystem->SetCVarInteger( name, value, flags );
}

void idCVarSystemLocal::SetCVarFloat( const char *name, const float value, int flags ) {
	cvarSystem->SetCVarFloat( name, value, flags );
}

const char * idCVarSystemLocal::GetCVarString( const char *name ) const {
	return cvarSystem->GetCVarString( name );
}

bool idCVarSystemLocal::GetCVarBool( const char *name ) const {
	return cvarSystem->GetCVarBool( name );
}

int idCVarSystemLocal::GetCVarInteger( const char *name ) const {
	return cvarSystem->GetCVarInteger( name );
}

float idCVarSystemLocal::GetCVarFloat( const char *name ) const {
	return cvarSystem->GetCVarFloat( name );
}

bool idCVarSystemLocal::Command( const idCmdArgs &args ) {
	return cvarSystem->Command( args );
}

void idCVarSystemLocal::CommandCompletion( void(*callback)( const char *s ) ) {
	cvarSystem->CommandCompletion( callback );
}

void idCVarSystemLocal::ArgCompletion( const char *cmdString, void(*callback)( const char *s ) ) {
	cvarSystem->ArgCompletion( cmdString, callback );
}

void idCVarSystemLocal::SetModifiedFlags( int flags ) {
	cvarSystem->SetModifiedFlags( flags );
}

int idCVarSystemLocal::GetModifiedFlags( void ) const {
	return cvarSystem->GetModifiedFlags();
}

void idCVarSystemLocal::ClearModifiedFlags( int flags ) {
	cvarSystem->ClearModifiedFlags( flags );
}

void idCVarSystemLocal::ResetFlaggedVariables( int flags ) {
	cvarSystem->ResetFlaggedVariables( flags );
}

void idCVarSystemLocal::RemoveFlaggedAutoCompletion( int flags ) {
	cvarSystem->RemoveFlaggedAutoCompletion( flags );
}

void idCVarSystemLocal::WriteFlaggedVariables( int flags, const char *setCmd, idFile *f ) const {
	cvarSystem->WriteFlaggedVariables( flags, setCmd, f );
}

const idDict * idCVarSystemLocal::MoveCVarsToDict( int flags ) const {
	return cvarSystem->MoveCVarsToDict( flags );
}

void idCVarSystemLocal::SetCVarsFromDict( const idDict &dict ) {
	cvarSystem->SetCVarsFromDict( dict );
}

void idFileSystemLocal::Init( void ) {
	fileSystem->Init();
}

void idFileSystemLocal::Restart( void ) {
	fileSystem->Restart();
}

void idFileSystemLocal::Shutdown( bool reloading ) {
	fileSystem->Shutdown( reloading );
}

bool idFileSystemLocal::IsInitialized( void ) const {
	return fileSystem->IsInitialized();
}

bool idFileSystemLocal::PerformingCopyFiles( void ) const {
	return fileSystem->PerformingCopyFiles();
}

idModList * idFileSystemLocal::ListMods( void ) {
	return fileSystem->ListMods();
}

void idFileSystemLocal::FreeModList( idModList *modList ) {
	fileSystem->FreeModList( modList );
}

idFileList * idFileSystemLocal::ListFiles( const char *relativePath, const char *extension, bool sort, bool fullRelativePath, const char* gamedir ) {
	return fileSystem->ListFiles( relativePath, extension, sort, fullRelativePath, gamedir );
}

idFileList * idFileSystemLocal::ListFilesTree( const char *relativePath, const char *extension, bool sort, const char* gamedir ) {
	return fileSystem->ListFilesTree( relativePath, extension, sort, gamedir );
}

void idFileSystemLocal::FreeFileList( idFileList *fileList ) {
	fileSystem->FreeFileList( fileList );
}

const char * idFileSystemLocal::OSPathToRelativePath( const char *OSPath ) {
	return fileSystem->OSPathToRelativePath( OSPath );
}

const char * idFileSystemLocal::RelativePathToOSPath( const char *relativePath, const char *basePath ) {
	return fileSystem->RelativePathToOSPath( relativePath, basePath );
}

const char * idFileSystemLocal::BuildOSPath( const char *base, const char *game, const char *relativePath ) {
	return fileSystem->BuildOSPath( base, game, relativePath );
}

void idFileSystemLocal::CreateOSPath( const char *OSPath ) {
	fileSystem->CreateOSPath( OSPath );
}

bool idFileSystemLocal::FileIsInPAK( const char *relativePath ) {
	return fileSystem->FileIsInPAK( relativePath );
}

void idFileSystemLocal::UpdatePureServerChecksums( void ) {
	fileSystem->UpdatePureServerChecksums();
}

bool idFileSystemLocal::UpdateGamePakChecksums( void ) {
	return fileSystem->UpdateGamePakChecksums();
}

fsPureReply_t idFileSystemLocal::SetPureServerChecksums( const int pureChecksums[ MAX_PURE_PAKS ], int gamePakChecksum, int missingChecksums[ MAX_PURE_PAKS ], int *missingGamePakChecksum ) {
	return fileSystem->SetPureServerChecksums( pureChecksums, gamePakChecksum, missingChecksums, missingGamePakChecksum );
}

void idFileSystemLocal::GetPureServerChecksums( int checksums[ MAX_PURE_PAKS ], int OS, int *gamePakChecksum ) {
	fileSystem->GetPureServerChecksums( checksums, OS, gamePakChecksum );
}

void idFileSystemLocal::SetRestartChecksums( const int pureChecksums[ MAX_PURE_PAKS ], int gamePakChecksum ) {
	fileSystem->SetRestartChecksums( pureChecksums, gamePakChecksum );
}

void idFileSystemLocal::ClearPureChecksums( void ) {
	fileSystem->ClearPureChecksums();
}

int idFileSystemLocal::GetOSMask( void ) {
	return fileSystem->GetOSMask();
}

int idFileSystemLocal::ReadFile( const char *relativePath, void **buffer, ID_TIME_T *timestamp ) {
	return fileSystem->ReadFile( relativePath, buffer, timestamp );
}

void idFileSystemLocal::FreeFile( void *buffer ) {
	fileSystem->FreeFile( buffer );
}

int idFileSystemLocal::WriteFile( const char *relativePath, const void *buffer, int size, const char *basePath ) {
	return fileSystem->WriteFile( relativePath, buffer, size, basePath );
}

void idFileSystemLocal::RemoveFile( const char *relativePath ) {
	fileSystem->RemoveFile( relativePath );
}

idFile * idFileSystemLocal::OpenFileRead( const char *relativePath, bool allowCopyFiles, const char* gamedir ) {
	return fileSystem->OpenFileRead( relativePath, allowCopyFiles, gamedir );
}

idFile * idFileSystemLocal::OpenFileWrite( const char *relativePath, const char *basePath ) {
	return fileSystem->OpenFileWrite( relativePath, basePath );
}

idFile * idFileSystemLocal::OpenFileAppend( const char *filename, bool sync, const char *basePath ) {
	return fileSystem->OpenFileAppend( filename, sync, basePath );
}

idFile * idFileSystemLocal::OpenFileByMode( const char *relativePath, fsMode_t mode ) {
	return fileSystem->OpenFileByMode( relativePath, mode );
}

idFile * idFileSystemLocal::OpenExplicitFileRead( const char *OSPath ) {
	return fileSystem->OpenExplicitFileRead( OSPath );
}

idFile * idFileSystemLocal::OpenExplicitFileWrite( const char *OSPath ) {
	return fileSystem->OpenExplicitFileWrite( OSPath );
}

void idFileSystemLocal::CloseFile( idFile *f ) {
	fileSystem->CloseFile( f );
}

void idFileSystemLocal::BackgroundDownload( backgroundDownload_t *bgl ) {
	fileSystem->BackgroundDownload( bgl );
}

void idFileSystemLocal::ResetReadCount( void ) {
	fileSystem->ResetReadCount();
}

int idFileSystemLocal::GetReadCount( void ) {
	return fileSystem->GetReadCount();
}

void idFileSystemLocal::AddToReadCount( int c ) {
	fileSystem->AddToReadCount( c );
}

void idFileSystemLocal::FindDLL( const char *basename, char dllPath[ MAX_OSPATH ], bool updateChecksum ) {
	fileSystem->FindDLL( basename, dllPath, updateChecksum );
}

void idFileSystemLocal::ClearDirCache( void ) {
	fileSystem->ClearDirCache();
}

bool idFileSystemLocal::HasD3XP( void ) {
	return fileSystem->HasD3XP();
}

bool idFileSystemLocal::RunningD3XP( void ) {
	return fileSystem->RunningD3XP();
}

void idFileSystemLocal::CopyFile( const char *fromOSPath, const char *toOSPath ) {
	fileSystem->CopyFile( fromOSPath, toOSPath );
}

int idFileSystemLocal::ValidateDownloadPakForChecksum( int checksum, char path[ MAX_STRING_CHARS ], bool isGamePak ) {
	return fileSystem->ValidateDownloadPakForChecksum( checksum, path, isGamePak );
}

idFile * idFileSystemLocal::MakeTemporaryFile( void ) {
	return fileSystem->MakeTemporaryFile();
}

int idFileSystemLocal::AddZipFile( const char *path ) {
	return fileSystem->AddZipFile( path );
}

findFile_t idFileSystemLocal::FindFile( const char *path, bool scheduleAddons ) {
	return fileSystem->FindFile( path, scheduleAddons );
}

int idFileSystemLocal::GetNumMaps() {
	return fileSystem->GetNumMaps();
}

const idDict * idFileSystemLocal::GetMapDecl( int i ) {
	return fileSystem->GetMapDecl( i );
}

void idFileSystemLocal::FindMapScreenshot( const char *path, char *buf, int len ) {
	fileSystem->FindMapScreenshot( path, buf, len );
}

bool idFileSystemLocal::FilenameCompare( const char *s1, const char *s2 ) const {
	return fileSystem->FilenameCompare( s1, s2 );
}

void idNetworkSystemLocal::ServerSendReliableMessage( int clientNum, const idBitMsg &msg ) {
	if ( idBotFacade::IsBot( clientNum ) ) {
		// TODO: bots should handle this message
//		return;
	}
	networkSystem->ServerSendReliableMessage( clientNum, msg );
}

void idNetworkSystemLocal::ServerSendReliableMessageExcluding( int clientNum, const idBitMsg &msg ) {
	if ( idBotFacade::IsBot( clientNum ) ) {
		// TODO: bots should handle this message
//		return;
	}
	networkSystem->ServerSendReliableMessageExcluding( clientNum, msg );
}

int idNetworkSystemLocal::ServerGetClientPing( int clientNum ) {
	if ( idBotFacade::IsBot( clientNum ) ) {
		return 5; // ping = 5 for bots (same as Half-Life) ;)
	}
	return networkSystem->ServerGetClientPing( clientNum );
}

int idNetworkSystemLocal::ServerGetClientPrediction( int clientNum ) {
	return networkSystem->ServerGetClientPrediction( clientNum );
}

int idNetworkSystemLocal::ServerGetClientTimeSinceLastPacket( int clientNum ) {
	if ( idBotFacade::IsBot( clientNum ) ) {
		return 0; // bots do not lag
	}
	return networkSystem->ServerGetClientTimeSinceLastPacket( clientNum );
}

int idNetworkSystemLocal::ServerGetClientTimeSinceLastInput( int clientNum ) {
	if ( idBotFacade::IsBot( clientNum ) ) {
		return 0; // bots do not lag
	}
	return networkSystem->ServerGetClientTimeSinceLastInput( clientNum );
}

int idNetworkSystemLocal::ServerGetClientOutgoingRate( int clientNum ) {
	return networkSystem->ServerGetClientOutgoingRate( clientNum );
}

int idNetworkSystemLocal::ServerGetClientIncomingRate( int clientNum ) {
	return networkSystem->ServerGetClientIncomingRate( clientNum );
}

float idNetworkSystemLocal::ServerGetClientIncomingPacketLoss( int clientNum ) {
	return networkSystem->ServerGetClientIncomingPacketLoss( clientNum );
}

void idNetworkSystemLocal::ClientSendReliableMessage( const idBitMsg &msg ) {
	networkSystem->ClientSendReliableMessage( msg );
}

int idNetworkSystemLocal::ClientGetPrediction( void ) {
	return networkSystem->ClientGetPrediction();
}

int idNetworkSystemLocal::ClientGetTimeSinceLastPacket( void ) {
	return networkSystem->ClientGetTimeSinceLastPacket();
}

int idNetworkSystemLocal::ClientGetOutgoingRate( void ) {
	return networkSystem->ClientGetOutgoingRate();
}

int idNetworkSystemLocal::ClientGetIncomingRate( void ) {
	return networkSystem->ClientGetIncomingRate();
}

float idNetworkSystemLocal::ClientGetIncomingPacketLoss( void ) {
	return networkSystem->ClientGetIncomingPacketLoss();
}

void idRenderSystemLocal::Init( void ) {
	renderSystem->Init();
}

void idRenderSystemLocal::Shutdown( void ) {
	renderSystem->Shutdown();
}

void idRenderSystemLocal::InitOpenGL( void ) {
	renderSystem->InitOpenGL();
}

void idRenderSystemLocal::ShutdownOpenGL( void ) {
	renderSystem->ShutdownOpenGL();
}

bool idRenderSystemLocal::IsOpenGLRunning( void ) const {
	return renderSystem->IsOpenGLRunning();
}

bool idRenderSystemLocal::IsFullScreen( void ) const {
	return renderSystem->IsFullScreen();
}

int idRenderSystemLocal::GetScreenWidth( void ) const {
	return renderSystem->GetScreenWidth();
}

int idRenderSystemLocal::GetScreenHeight( void ) const {
	return renderSystem->GetScreenHeight();
}

idRenderWorld * idRenderSystemLocal::AllocRenderWorld( void ) {
	return renderSystem->AllocRenderWorld();
}

void idRenderSystemLocal::FreeRenderWorld( idRenderWorld * rw ) {
	renderSystem->FreeRenderWorld( rw );
}

void idRenderSystemLocal::BeginLevelLoad( void ) {
	renderSystem->BeginLevelLoad();
}

void idRenderSystemLocal::EndLevelLoad( void ) {
	renderSystem->EndLevelLoad();
}

bool idRenderSystemLocal::RegisterFont( const char *fontName, fontInfoEx_t &font ) {
	return renderSystem->RegisterFont( fontName, font );
}

void idRenderSystemLocal::SetColor( const idVec4 &rgba ) {
	renderSystem->SetColor( rgba );
}

void idRenderSystemLocal::SetColor4( float r, float g, float b, float a ) {
	renderSystem->SetColor4( r, g, b, a );
}

void idRenderSystemLocal::DrawStretchPic( const idDrawVert *verts, const glIndex_t *indexes, int vertCount, int indexCount, const idMaterial *material,
										  bool clip, float min_x, float min_y, float max_x, float max_y ) {
	renderSystem->DrawStretchPic( verts, indexes, vertCount, indexCount, material, clip, min_x, min_y, max_x, max_y );
}

void idRenderSystemLocal::DrawStretchPic( float x, float y, float w, float h, float s1, float t1, float s2, float t2, const idMaterial *material ) {
	renderSystem->DrawStretchPic( x, y, w, h, s1, t1, s2, t2, material );
}

void idRenderSystemLocal::DrawStretchTri ( idVec2 p1, idVec2 p2, idVec2 p3, idVec2 t1, idVec2 t2, idVec2 t3, const idMaterial *material ) {
	renderSystem->DrawStretchTri( p1, p2, p3, t1, t2, t3, material );
}

void idRenderSystemLocal::GlobalToNormalizedDeviceCoordinates( const idVec3 &global, idVec3 &ndc ) {
	renderSystem->GlobalToNormalizedDeviceCoordinates( global, ndc );
}

void idRenderSystemLocal::GetGLSettings( int& width, int& height ) {
	renderSystem->GetGLSettings( width, height );
}

void idRenderSystemLocal::PrintMemInfo( MemInfo_t *mi ) {
	renderSystem->PrintMemInfo( mi );
}

void idRenderSystemLocal::DrawSmallChar( int x, int y, int ch, const idMaterial *material ) {
	renderSystem->DrawSmallChar( x, y, ch, material );
}

void idRenderSystemLocal::DrawSmallStringExt( int x, int y, const char *string, const idVec4 &setColor, bool forceColor, const idMaterial *material ) {
	renderSystem->DrawSmallStringExt( x, y, string, setColor, forceColor, material );
}

void idRenderSystemLocal::DrawBigChar( int x, int y, int ch, const idMaterial *material ) {
	renderSystem->DrawBigChar( x, y, ch, material );
}

void idRenderSystemLocal::DrawBigStringExt( int x, int y, const char *string, const idVec4 &setColor, bool forceColor, const idMaterial *material ) {
	renderSystem->DrawBigStringExt( x, y, string, setColor, forceColor, material );
}

void idRenderSystemLocal::WriteDemoPics() {
	renderSystem->WriteDemoPics();
}

void idRenderSystemLocal::DrawDemoPics() {
	renderSystem->DrawDemoPics();
}

void idRenderSystemLocal::BeginFrame( int windowWidth, int windowHeight ) {
	renderSystem->BeginFrame( windowWidth, windowHeight );
}

void idRenderSystemLocal::EndFrame( int *frontEndMsec, int *backEndMsec ) {
	renderSystem->EndFrame( frontEndMsec, backEndMsec );
}

void idRenderSystemLocal::TakeScreenshot( int width, int height, const char *fileName, int samples, struct renderView_s *ref ) {
	renderSystem->TakeScreenshot( width, height, fileName, samples, ref );
}

void idRenderSystemLocal::CropRenderSize( int width, int height, bool makePowerOfTwo, bool forceDimensions ) {
	renderSystem->CropRenderSize( width, height, makePowerOfTwo, forceDimensions );
}

void idRenderSystemLocal::CaptureRenderToImage( const char *imageName ) {
	renderSystem->CaptureRenderToImage( imageName );
}

void idRenderSystemLocal::CaptureRenderToFile( const char *fileName, bool fixAlpha ) {
	renderSystem->CaptureRenderToFile( fileName, fixAlpha );
}

void idRenderSystemLocal::UnCrop() {
	renderSystem->UnCrop();
}

void idRenderSystemLocal::GetCardCaps( bool &oldCard, bool &nv10or20 ) {
	renderSystem->GetCardCaps( oldCard, nv10or20 );
}

bool idRenderSystemLocal::UploadImage( const char *imageName, const byte *data, int width, int height ) {
	return renderSystem->UploadImage( imageName, data, width, height );
}

void idSoundSystemLocal::Init( void ) {
	soundSystem->Init();
}

void idSoundSystemLocal::Shutdown( void ) {
	soundSystem->Shutdown();
}

void idSoundSystemLocal::ClearBuffer( void ) {
	soundSystem->ClearBuffer();
}

bool idSoundSystemLocal::InitHW( void ) {
	return soundSystem->InitHW();
}

bool idSoundSystemLocal::ShutdownHW( void ) {
	return soundSystem->ShutdownHW();
}

int idSoundSystemLocal::AsyncUpdate( int time ) {
	return soundSystem->AsyncUpdate( time );
}

int idSoundSystemLocal::AsyncUpdateWrite( int time ) {
	return soundSystem->AsyncUpdateWrite( time );
}

void idSoundSystemLocal::SetMute( bool mute ) {
	soundSystem->SetMute( mute );
}

cinData_t idSoundSystemLocal::ImageForTime( const int milliseconds, const bool waveform ) {
	return soundSystem->ImageForTime( milliseconds, waveform );
}

int idSoundSystemLocal::GetSoundDecoderInfo( int index, soundDecoderInfo_t &decoderInfo ) {
	return soundSystem->GetSoundDecoderInfo( index, decoderInfo );
}

idSoundWorld * idSoundSystemLocal::AllocSoundWorld( idRenderWorld *rw ) {
	return soundSystem->AllocSoundWorld( rw );
}

void idSoundSystemLocal::SetPlayingSoundWorld( idSoundWorld *soundWorld ) {
	soundSystem->SetPlayingSoundWorld( soundWorld );
}

idSoundWorld * idSoundSystemLocal::GetPlayingSoundWorld( void ) {
	return soundSystem->GetPlayingSoundWorld();
}

void idSoundSystemLocal::BeginLevelLoad( void ) {
	soundSystem->BeginLevelLoad();
}

void idSoundSystemLocal::EndLevelLoad( const char *mapString ) {
	soundSystem->EndLevelLoad( mapString );
}

int idSoundSystemLocal::AsyncMix( int soundTime, float *mixBuffer ) {
	return soundSystem->AsyncMix( soundTime, mixBuffer );
}

void idSoundSystemLocal::PrintMemInfo( MemInfo_t *mi ) {
	soundSystem->PrintMemInfo( mi );
}

int idSoundSystemLocal::IsEAXAvailable( void ) {
	return soundSystem->IsEAXAvailable();
}

void idRenderModelManagerLocal::Init() {
	renderModelManager->Init();
}

void idRenderModelManagerLocal::Shutdown() {
	renderModelManager->Shutdown();
}

void idRenderModelManagerLocal::BeginLevelLoad() {
	renderModelManager->BeginLevelLoad();
}

void idRenderModelManagerLocal::EndLevelLoad() {
	renderModelManager->EndLevelLoad();
}

idRenderModel * idRenderModelManagerLocal::AllocModel() {
	return renderModelManager->AllocModel();
}

void idRenderModelManagerLocal::FreeModel( idRenderModel *model ) {
	renderModelManager->FreeModel( model );
}

idRenderModel * idRenderModelManagerLocal::FindModel( const char *modelName ) {
	return renderModelManager->FindModel( modelName );
}

idRenderModel * idRenderModelManagerLocal::CheckModel( const char *modelName ) {
	return renderModelManager->CheckModel( modelName );
}

idRenderModel * idRenderModelManagerLocal::DefaultModel() {
	return renderModelManager->DefaultModel();
}

void idRenderModelManagerLocal::AddModel( idRenderModel *model ) {
	renderModelManager->AddModel( model );
}

void idRenderModelManagerLocal::RemoveModel( idRenderModel *model ) {
	renderModelManager->RemoveModel( model );
}

void idRenderModelManagerLocal::ReloadModels( bool forceAll ) {
	renderModelManager->ReloadModels( forceAll );
}

void idRenderModelManagerLocal::WritePrecacheCommands( idFile *f ) {
	renderModelManager->WritePrecacheCommands( f );
}

void idRenderModelManagerLocal::FreeModelVertexCaches() {
	renderModelManager->FreeModelVertexCaches();
}

void idRenderModelManagerLocal::PrintMemInfo( MemInfo_t *mi ) {
	renderModelManager->PrintMemInfo( mi );
}

void idUserInterfaceManagerLocal::Init() {
	uiManager->Init();
}

void idUserInterfaceManagerLocal::Shutdown() {
	uiManager->Shutdown();
}

void idUserInterfaceManagerLocal::Touch( const char *name ) {
	uiManager->Touch( name );
}

void idUserInterfaceManagerLocal::WritePrecacheCommands( idFile *f ) {
	uiManager->WritePrecacheCommands( f );
}

void idUserInterfaceManagerLocal::SetSize( float width, float height ) {
	uiManager->SetSize( width, height );
}

void idUserInterfaceManagerLocal::BeginLevelLoad() {
	uiManager->BeginLevelLoad();
}

void idUserInterfaceManagerLocal::EndLevelLoad() {
	uiManager->EndLevelLoad();
}

void idUserInterfaceManagerLocal::Reload( bool all ) {
	uiManager->Reload( all );
}

void idUserInterfaceManagerLocal::ListGuis() const {
	uiManager->ListGuis();
}

bool idUserInterfaceManagerLocal::CheckGui( const char *qpath ) const {
	return uiManager->CheckGui( qpath );
}

idUserInterface * idUserInterfaceManagerLocal::Alloc( void ) const {
	return uiManager->Alloc();
}

void idUserInterfaceManagerLocal::DeAlloc( idUserInterface *gui ) {
	uiManager->DeAlloc( gui );
}

idUserInterface * idUserInterfaceManagerLocal::FindGui( const char *qpath, bool autoLoad, bool needUnique, bool forceUnique ) {
	return uiManager->FindGui( qpath, autoLoad, needUnique, forceUnique );
}

idUserInterface * idUserInterfaceManagerLocal::FindDemoGui( const char *qpath ) {
	return uiManager->FindDemoGui( qpath );
}

idListGUI * idUserInterfaceManagerLocal::AllocListGUI( void ) const {
	return uiManager->AllocListGUI();
}

void idUserInterfaceManagerLocal::FreeListGUI( idListGUI *listgui ) {
	uiManager->FreeListGUI( listgui );
}

void idDeclManagerLocal::Init( void ) {
	declManager->Init();
}

void idDeclManagerLocal::Shutdown( void ) {
	declManager->Shutdown();
}

void idDeclManagerLocal::Reload( bool force ) {
	declManager->Reload( force );
}

void idDeclManagerLocal::BeginLevelLoad() {
	declManager->BeginLevelLoad();
}

void idDeclManagerLocal::EndLevelLoad() {
	declManager->EndLevelLoad();
}

void idDeclManagerLocal::RegisterDeclType( const char *typeName, declType_t type, idDecl *(*allocator)( void ) ) {
	declManager->RegisterDeclType( typeName, type, allocator );
}

void idDeclManagerLocal::RegisterDeclFolder( const char *folder, const char *extension, declType_t defaultType ) {
	declManager->RegisterDeclFolder( folder, extension, defaultType );
}

int idDeclManagerLocal::GetChecksum( void ) const {
	return declManager->GetChecksum();
}

int idDeclManagerLocal::GetNumDeclTypes( void ) const {
	return declManager->GetNumDeclTypes();
}

const char * idDeclManagerLocal::GetDeclNameFromType( declType_t type ) const {
	return declManager->GetDeclNameFromType( type );
}

declType_t idDeclManagerLocal::GetDeclTypeFromName( const char *typeName ) const {
	return declManager->GetDeclTypeFromName( typeName );
}

const idDecl * idDeclManagerLocal::FindType( declType_t type, const char *name, bool makeDefault ) {
	return declManager->FindType( type, name, makeDefault );
}

const idDecl * idDeclManagerLocal::FindDeclWithoutParsing( declType_t type, const char *name, bool makeDefault ) {
	return declManager->FindDeclWithoutParsing( type, name, makeDefault );
}

void idDeclManagerLocal::ReloadFile( const char* filename, bool force ) {
	declManager->ReloadFile( filename, force );
}

int idDeclManagerLocal::GetNumDecls( declType_t type ) {
	return declManager->GetNumDecls( type );
}

const idDecl * idDeclManagerLocal::DeclByIndex( declType_t type, int index, bool forceParse ) {
	return declManager->DeclByIndex( type, index, forceParse );
}

void idDeclManagerLocal::ListType( const idCmdArgs &args, declType_t type ) {
	declManager->ListType( args, type );
}

void idDeclManagerLocal::PrintType( const idCmdArgs &args, declType_t type ) {
	declManager->PrintType( args, type );
}

idDecl * idDeclManagerLocal::CreateNewDecl( declType_t type, const char *name, const char *fileName ) {
	return declManager->CreateNewDecl( type, name, fileName );
}

bool idDeclManagerLocal::RenameDecl( declType_t type, const char* oldName, const char* newName ) {
	return declManager->RenameDecl( type, oldName, newName );
}

void idDeclManagerLocal::MediaPrint( const char *fmt, ... ) {
	char buf[4096];
	va_list argptr;

	va_start( argptr, fmt );
	idStr::vsnPrintf( buf, sizeof( buf ), fmt, argptr );
	va_end( argptr );

	declManager->MediaPrint( buf );
}

void idDeclManagerLocal::WritePrecacheCommands( idFile *f ) {
	declManager->WritePrecacheCommands( f );
}

const idMaterial * idDeclManagerLocal::FindMaterial( const char *name, bool makeDefault ) {
	return declManager->FindMaterial( name, makeDefault );
}

const idDeclSkin * idDeclManagerLocal::FindSkin( const char *name, bool makeDefault ) {
	return declManager->FindSkin( name, makeDefault );
}

const idSoundShader * idDeclManagerLocal::FindSound( const char *name, bool makeDefault ) {
	return declManager->FindSound( name, makeDefault );
}

const idMaterial * idDeclManagerLocal::MaterialByIndex( int index, bool forceParse ) {
	return declManager->MaterialByIndex( index, forceParse );
}

const idDeclSkin * idDeclManagerLocal::SkinByIndex( int index, bool forceParse ) {
	return declManager->SkinByIndex( index, forceParse );
}

const idSoundShader * idDeclManagerLocal::SoundByIndex( int index, bool forceParse ) {
	return declManager->SoundByIndex( index, forceParse );
}

idAASFile * idAASFileManagerLocal::LoadAAS( const char *fileName, unsigned int mapFileCRC ) {
	return AASFileManager->LoadAAS( fileName, mapFileCRC );
}

void idAASFileManagerLocal::FreeAAS( idAASFile *file ) {
	AASFileManager->FreeAAS( file );
}

void idCollisionModelManagerLocal::LoadMap( const idMapFile *mapFile ) {
	collisionModelManager->LoadMap( mapFile );
}

void idCollisionModelManagerLocal::FreeMap( void ) {
	collisionModelManager->FreeMap();
}

cmHandle_t idCollisionModelManagerLocal::LoadModel( const char *modelName, const bool precache ) {
	return collisionModelManager->LoadModel( modelName, precache );
}

cmHandle_t idCollisionModelManagerLocal::SetupTrmModel( const idTraceModel &trm, const idMaterial *material ) {
	return collisionModelManager->SetupTrmModel( trm, material );
}

bool idCollisionModelManagerLocal::TrmFromModel( const char *modelName, idTraceModel &trm ) {
	return collisionModelManager->TrmFromModel( modelName, trm );
}

const char * idCollisionModelManagerLocal::GetModelName( cmHandle_t model ) const {
	return collisionModelManager->GetModelName( model );
}

bool idCollisionModelManagerLocal::GetModelBounds( cmHandle_t model, idBounds &bounds ) const {
	return collisionModelManager->GetModelBounds( model, bounds );
}

bool idCollisionModelManagerLocal::GetModelContents( cmHandle_t model, int &contents ) const {
	return collisionModelManager->GetModelContents( model, contents );
}

bool idCollisionModelManagerLocal::GetModelVertex( cmHandle_t model, int vertexNum, idVec3 &vertex ) const {
	return collisionModelManager->GetModelVertex( model, vertexNum, vertex );
}

bool idCollisionModelManagerLocal::GetModelEdge( cmHandle_t model, int edgeNum, idVec3 &start, idVec3 &end ) const {
	return collisionModelManager->GetModelEdge( model, edgeNum, start, end );
}

bool idCollisionModelManagerLocal::GetModelPolygon( cmHandle_t model, int polygonNum, idFixedWinding &winding ) const {
	return collisionModelManager->GetModelPolygon( model, polygonNum, winding );
}

void idCollisionModelManagerLocal::Translation( trace_t *results, const idVec3 &start, const idVec3 &end,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis ) {
	collisionModelManager->Translation( results, start, end, trm, trmAxis, contentMask, model, modelOrigin, modelAxis );
}

void idCollisionModelManagerLocal::Rotation( trace_t *results, const idVec3 &start, const idRotation &rotation,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis ) {
	collisionModelManager->Rotation( results, start, rotation, trm, trmAxis, contentMask, model, modelOrigin, modelAxis );
}

int idCollisionModelManagerLocal::Contents( const idVec3 &start,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis ) {
	return collisionModelManager->Contents( start, trm, trmAxis, contentMask, model, modelOrigin, modelAxis );
}

int idCollisionModelManagerLocal::Contacts( contactInfo_t *contacts, const int maxContacts, const idVec3 &start, const idVec6 &dir, const float depth,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis ) {
	return collisionModelManager->Contacts( contacts, maxContacts, start, dir, depth, trm, trmAxis, contentMask, model, modelOrigin, modelAxis );
}

void idCollisionModelManagerLocal::DebugOutput( const idVec3 &origin ) {
	collisionModelManager->DebugOutput( origin );
}

void idCollisionModelManagerLocal::DrawModel( cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis,
												const idVec3 &viewOrigin, const float radius ) {
	collisionModelManager->DrawModel( model, modelOrigin, modelAxis, viewOrigin, radius );
}

void idCollisionModelManagerLocal::ModelInfo( cmHandle_t model ) {
	collisionModelManager->ModelInfo( model );
}

void idCollisionModelManagerLocal::ListModels( void ) {
	collisionModelManager->ListModels();
}

bool idCollisionModelManagerLocal::WriteCollisionModelForMapEntity( const idMapEntity *mapEnt, const char *filename, const bool testTraceModel ) {
	return collisionModelManager->WriteCollisionModelForMapEntity( mapEnt, filename, testTraceModel );
}
