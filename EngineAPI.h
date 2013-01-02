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

#ifndef ENGINE_API_H
#define ENGINE_API_H

class idSysLocal : public idSys {
public:
	virtual void			DebugPrintf( const char *fmt, ... )id_attribute((format(printf,2,3)));
	virtual void			DebugVPrintf( const char *fmt, va_list arg );

	virtual double			GetClockTicks( void );
	virtual double			ClockTicksPerSecond( void );
	virtual cpuid_t			GetProcessorId( void );
	virtual const char *	GetProcessorString( void );
	virtual const char *	FPU_GetState( void );
	virtual bool			FPU_StackIsEmpty( void );
	virtual void			FPU_SetFTZ( bool enable );
	virtual void			FPU_SetDAZ( bool enable );

	virtual void			FPU_EnableExceptions( int exceptions );

	virtual bool			LockMemory( void *ptr, int bytes );
	virtual bool			UnlockMemory( void *ptr, int bytes );

	virtual void			GetCallStack( address_t *callStack, const int callStackSize );
	virtual const char *	GetCallStackStr( const address_t *callStack, const int callStackSize );
	virtual const char *	GetCallStackCurStr( int depth );
	virtual void			ShutdownSymbols( void );

	virtual int				DLL_Load( const char *dllName );
	virtual void *			DLL_GetProcAddress( int dllHandle, const char *procName );
	virtual void			DLL_Unload( int dllHandle );
	virtual void			DLL_GetFileName( const char *baseName, char *dllName, int maxLength );

	virtual sysEvent_t		GenerateMouseButtonEvent( int button, bool down );
	virtual sysEvent_t		GenerateMouseMoveEvent( int deltax, int deltay );

	virtual void			OpenURL( const char *url, bool quit );
	virtual void			StartProcess( const char *exePath, bool quit );
};

class idCommonLocal : public idCommon {
public:
	virtual						~idCommonLocal( void ) {}

								// Initialize everything.
								// if the OS allows, pass argc/argv directly (without executable name)
								// otherwise pass the command line in a single string (without executable name)
	virtual void				Init( int argc, const char **argv, const char *cmdline );

								// Shuts down everything.
	virtual void				Shutdown( void );

								// Shuts down everything.
	virtual void				Quit( void );

								// Returns true if common initialization is complete.
	virtual bool				IsInitialized( void ) const;

								// Called repeatedly as the foreground thread for rendering and game logic.
	virtual void				Frame( void );

								// Called repeatedly by blocking function calls with GUI interactivity.
	virtual void				GUIFrame( bool execCmd, bool network );

								// Called 60 times a second from a background thread for sound mixing,
								// and input generation. Not called until idCommon::Init() has completed.
	virtual void				Async( void );

								// Checks for and removes command line "+set var arg" constructs.
								// If match is NULL, all set commands will be executed, otherwise
								// only a set with the exact name.  Only used during startup.
								// set once to clear the cvar from +set for early init code
	virtual void				StartupVariable( const char *match, bool once );

								// Initializes a tool with the given dictionary.
	virtual void				InitTool( const toolFlag_t tool, const idDict *dict );

								// Activates or deactivates a tool.
	virtual void				ActivateTool( bool active );

								// Writes the user's configuration to a file
	virtual void				WriteConfigToFile( const char *filename );

								// Writes cvars with the given flags to a file.
	virtual void				WriteFlaggedCVarsToFile( const char *filename, int flags, const char *setCmd );

								// Begins redirection of console output to the given buffer.
	virtual void				BeginRedirect( char *buffer, int buffersize, void (*flush)( const char * ) );

								// Stops redirection of console output.
	virtual void				EndRedirect( void );

								// Update the screen with every message printed.
	virtual void				SetRefreshOnPrint( bool set );

								// Prints message to the console, which may cause a screen update if com_refreshOnPrint is set.
	virtual void				Printf( const char *fmt, ... )id_attribute((format(printf,2,3)));

								// Same as Printf, with a more usable API - Printf pipes to this.
	virtual void				VPrintf( const char *fmt, va_list arg );

								// Prints message that only shows up if the "developer" cvar is set,
								// and NEVER forces a screen update, which could cause reentrancy problems.
	virtual void				DPrintf( const char *fmt, ... ) id_attribute((format(printf,2,3)));

								// Prints WARNING %s message and adds the warning message to a queue for printing later on.
	virtual void				Warning( const char *fmt, ... ) id_attribute((format(printf,2,3)));

								// Prints WARNING %s message in yellow that only shows up if the "developer" cvar is set.
	virtual void				DWarning( const char *fmt, ...) id_attribute((format(printf,2,3)));

								// Prints all queued warnings.
	virtual void				PrintWarnings( void );

								// Removes all queued warnings.
	virtual void				ClearWarnings( const char *reason );

								// Issues a C++ throw. Normal errors just abort to the game loop,
								// which is appropriate for media or dynamic logic errors.
	virtual void				Error( const char *fmt, ... ) id_attribute((format(printf,2,3)));

								// Fatal errors quit all the way to a system dialog box, which is appropriate for
								// static internal errors or cases where the system may be corrupted.
	virtual void				FatalError( const char *fmt, ... ) id_attribute((format(printf,2,3)));

								// Returns a pointer to the dictionary with language specific strings.
	virtual const idLangDict *	GetLanguageDict( void );

								// Returns key bound to the command
	virtual const char *		KeysFromBinding( const char *bind );

								// Returns the binding bound to the key
	virtual const char *		BindingFromKey( const char *key ); 

								// Directly sample a button.
	virtual int					ButtonState( int key );

								// Directly sample a keystate.
	virtual int					KeyState( int key );
};

class idCmdSystemLocal : public idCmdSystem {
public:
	virtual				~idCmdSystemLocal( void ) {}

	virtual void		Init( void );
	virtual void		Shutdown( void );

						// Registers a command and the function to call for it.
	virtual void		AddCommand( const char *cmdName, cmdFunction_t function, int flags, const char *description, argCompletion_t argCompletion = NULL );
						// Removes a command.
	virtual void		RemoveCommand( const char *cmdName );
						// Remove all commands with one of the flags set.
	virtual void		RemoveFlaggedCommands( int flags );

						// Command and argument completion using callback for each valid string.
	virtual void		CommandCompletion( void(*callback)( const char *s ) );
	virtual void		ArgCompletion( const char *cmdString, void(*callback)( const char *s ) );

						// Adds command text to the command buffer, does not add a final \n
	virtual void		BufferCommandText( cmdExecution_t exec, const char *text );
						// Pulls off \n \r or ; terminated lines of text from the command buffer and
						// executes the commands. Stops when the buffer is empty.
						// Normally called once per frame, but may be explicitly invoked.
	virtual void		ExecuteCommandBuffer( void );

						// Base for path/file auto-completion.
	virtual void		ArgCompletion_FolderExtension( const idCmdArgs &args, void(*callback)( const char *s ), const char *folder, bool stripFolder, ... );
						// Base for decl name auto-completion.
	virtual void		ArgCompletion_DeclName( const idCmdArgs &args, void(*callback)( const char *s ), int type );

						// Adds to the command buffer in tokenized form ( CMD_EXEC_NOW or CMD_EXEC_APPEND only )
	virtual void		BufferCommandArgs( cmdExecution_t exec, const idCmdArgs &args );

						// Setup a reloadEngine to happen on next command run, and give a command to execute after reload
	virtual void		SetupReloadEngine( const idCmdArgs &args );
	virtual bool		PostReloadEngine( void );
};

class idCVarSystemLocal : public idCVarSystem {
public:
	virtual					~idCVarSystemLocal( void ) {}

	virtual void			Init( void );
	virtual void			Shutdown( void );
	virtual bool			IsInitialized( void ) const;

							// Registers a CVar.
	virtual void			Register( idCVar *cvar );

							// Finds the CVar with the given name.
							// Returns NULL if there is no CVar with the given name.
	virtual idCVar *		Find( const char *name );

							// Sets the value of a CVar by name.
	virtual void			SetCVarString( const char *name, const char *value, int flags = 0 );
	virtual void			SetCVarBool( const char *name, const bool value, int flags = 0 );
	virtual void			SetCVarInteger( const char *name, const int value, int flags = 0 );
	virtual void			SetCVarFloat( const char *name, const float value, int flags = 0 );

							// Gets the value of a CVar by name.
	virtual const char *	GetCVarString( const char *name ) const;
	virtual bool			GetCVarBool( const char *name ) const;
	virtual int				GetCVarInteger( const char *name ) const;
	virtual float			GetCVarFloat( const char *name ) const;

							// Called by the command system when argv(0) doesn't match a known command.
							// Returns true if argv(0) is a variable reference and prints or changes the CVar.
	virtual bool			Command( const idCmdArgs &args );

							// Command and argument completion using callback for each valid string.
	virtual void			CommandCompletion( void(*callback)( const char *s ) );
	virtual void			ArgCompletion( const char *cmdString, void(*callback)( const char *s ) );

							// Sets/gets/clears modified flags that tell what kind of CVars have changed.
	virtual void			SetModifiedFlags( int flags );
	virtual int				GetModifiedFlags( void ) const;
	virtual void			ClearModifiedFlags( int flags );

							// Resets variables with one of the given flags set.
	virtual void			ResetFlaggedVariables( int flags );

							// Removes auto-completion from the flagged variables.
	virtual void			RemoveFlaggedAutoCompletion( int flags );

							// Writes variables with one of the given flags set to the given file.
	virtual void			WriteFlaggedVariables( int flags, const char *setCmd, idFile *f ) const;

							// Moves CVars to and from dictionaries.
	virtual const idDict *	MoveCVarsToDict( int flags ) const;
	virtual void			SetCVarsFromDict( const idDict &dict );
};

class idFileSystemLocal : public idFileSystem {
public:
	virtual					~idFileSystemLocal() {}
							// Initializes the file system.
	virtual void			Init( void );
							// Restarts the file system.
	virtual void			Restart( void );
							// Shutdown the file system.
	virtual void			Shutdown( bool reloading );
							// Returns true if the file system is initialized.
	virtual bool			IsInitialized( void ) const;
							// Returns true if we are doing an fs_copyfiles.
	virtual bool			PerformingCopyFiles( void ) const;
							// Returns a list of mods found along with descriptions
							// 'mods' contains the directory names to be passed to fs_game
							// 'descriptions' contains a free form string to be used in the UI
	virtual idModList *		ListMods( void );
							// Frees the given mod list
	virtual void			FreeModList( idModList *modList );
							// Lists files with the given extension in the given directory.
							// Directory should not have either a leading or trailing '/'
							// The returned files will not include any directories or '/' unless fullRelativePath is set.
							// The extension must include a leading dot and may not contain wildcards.
							// If extension is "/", only subdirectories will be returned.
	virtual idFileList *	ListFiles( const char *relativePath, const char *extension, bool sort = false, bool fullRelativePath = false, const char* gamedir = NULL );
							// Lists files in the given directory and all subdirectories with the given extension.
							// Directory should not have either a leading or trailing '/'
							// The returned files include a full relative path.
							// The extension must include a leading dot and may not contain wildcards.
	virtual idFileList *	ListFilesTree( const char *relativePath, const char *extension, bool sort = false, const char* gamedir = NULL );
							// Frees the given file list.
	virtual void			FreeFileList( idFileList *fileList );
							// Converts a relative path to a full OS path.
	virtual const char *	OSPathToRelativePath( const char *OSPath );
							// Converts a full OS path to a relative path.
	virtual const char *	RelativePathToOSPath( const char *relativePath, const char *basePath = "fs_devpath" );
							// Builds a full OS path from the given components.
	virtual const char *	BuildOSPath( const char *base, const char *game, const char *relativePath );
							// Creates the given OS path for as far as it doesn't exist already.
	virtual void			CreateOSPath( const char *OSPath );
							// Returns true if a file is in a pak file.
	virtual bool			FileIsInPAK( const char *relativePath );
							// Returns a space separated string containing the checksums of all referenced pak files.
							// will call SetPureServerChecksums internally to restrict itself
	virtual void			UpdatePureServerChecksums( void );
							// setup the mapping of OS -> game pak checksum
	virtual bool			UpdateGamePakChecksums( void );
							// 0-terminated list of pak checksums
							// if pureChecksums[ 0 ] == 0, all data sources will be allowed
							// otherwise, only pak files that match one of the checksums will be checked for files
							// with the sole exception of .cfg files.
							// the function tries to configure pure mode from the paks already referenced and this new list
							// it returns wether the switch was successfull, and sets the missing checksums
							// the process is verbosive when fs_debug 1
	virtual fsPureReply_t	SetPureServerChecksums( const int pureChecksums[ MAX_PURE_PAKS ], int gamePakChecksum, int missingChecksums[ MAX_PURE_PAKS ], int *missingGamePakChecksum );
							// fills a 0-terminated list of pak checksums for a client
							// if OS is -1, give the current game pak checksum. if >= 0, lookup the game pak table (server only)
	virtual void			GetPureServerChecksums( int checksums[ MAX_PURE_PAKS ], int OS, int *gamePakChecksum );
							// before doing a restart, force the pure list and the search order
							// if the given checksum list can't be completely processed and set, will error out
	virtual void			SetRestartChecksums( const int pureChecksums[ MAX_PURE_PAKS ], int gamePakChecksum );
							// equivalent to calling SetPureServerChecksums with an empty list
	virtual	void			ClearPureChecksums( void );
							// get a mask of supported OSes. if not pure, returns -1
	virtual int				GetOSMask( void );
							// Reads a complete file.
							// Returns the length of the file, or -1 on failure.
							// A null buffer will just return the file length without loading.
							// A null timestamp will be ignored.
							// As a quick check for existance. -1 length == not present.
							// A 0 byte will always be appended at the end, so string ops are safe.
							// The buffer should be considered read-only, because it may be cached for other uses.
	virtual int				ReadFile( const char *relativePath, void **buffer, ID_TIME_T *timestamp = NULL );
							// Frees the memory allocated by ReadFile.
	virtual void			FreeFile( void *buffer );
							// Writes a complete file, will create any needed subdirectories.
							// Returns the length of the file, or -1 on failure.
	virtual int				WriteFile( const char *relativePath, const void *buffer, int size, const char *basePath = "fs_savepath" );
							// Removes the given file.
	virtual void			RemoveFile( const char *relativePath );
							// Opens a file for reading.
	virtual idFile *		OpenFileRead( const char *relativePath, bool allowCopyFiles = true, const char* gamedir = NULL );
							// Opens a file for writing, will create any needed subdirectories.
	virtual idFile *		OpenFileWrite( const char *relativePath, const char *basePath = "fs_savepath" );
							// Opens a file for writing at the end.
	virtual idFile *		OpenFileAppend( const char *filename, bool sync = false, const char *basePath = "fs_basepath" );
							// Opens a file for reading, writing, or appending depending on the value of mode.
	virtual idFile *		OpenFileByMode( const char *relativePath, fsMode_t mode );
							// Opens a file for reading from a full OS path.
	virtual idFile *		OpenExplicitFileRead( const char *OSPath );
							// Opens a file for writing to a full OS path.
	virtual idFile *		OpenExplicitFileWrite( const char *OSPath );
							// Closes a file.
	virtual void			CloseFile( idFile *f );
							// Returns immediately, performing the read from a background thread.
	virtual void			BackgroundDownload( backgroundDownload_t *bgl );
							// resets the bytes read counter
	virtual void			ResetReadCount( void );
							// retrieves the current read count
	virtual int				GetReadCount( void );
							// adds to the read count
	virtual void			AddToReadCount( int c );
							// look for a dynamic module
	virtual void			FindDLL( const char *basename, char dllPath[ MAX_OSPATH ], bool updateChecksum );
							// case sensitive filesystems use an internal directory cache
							// the cache is cleared when calling OpenFileWrite and RemoveFile
							// in some cases you may need to use this directly
	virtual void			ClearDirCache( void );

							// is D3XP installed? even if not running it atm
	virtual bool			HasD3XP( void );
							// are we using D3XP content ( through a real d3xp run or through a double mod )
	virtual bool			RunningD3XP( void );

							// don't use for large copies - allocates a single memory block for the copy
	virtual void			CopyFile( const char *fromOSPath, const char *toOSPath );

							// lookup a relative path, return the size or 0 if not found
	virtual int				ValidateDownloadPakForChecksum( int checksum, char path[ MAX_STRING_CHARS ], bool isGamePak );

	virtual idFile *		MakeTemporaryFile( void );

							// make downloaded pak files known so pure negociation works next time
	virtual int				AddZipFile( const char *path );

							// look for a file in the loaded paks or the addon paks
							// if the file is found in addons, FS's internal structures are ready for a reloadEngine
	virtual findFile_t		FindFile( const char *path, bool scheduleAddons = false );

							// get map/addon decls and take into account addon paks that are not on the search list
							// the decl 'name' is in the "path" entry of the dict
	virtual int				GetNumMaps();
	virtual const idDict *	GetMapDecl( int i );
	virtual void			FindMapScreenshot( const char *path, char *buf, int len );

							// ignore case and seperator char distinctions
	virtual bool			FilenameCompare( const char *s1, const char *s2 ) const;
};

class idNetworkSystemLocal : public idNetworkSystem {
public:
	virtual					~idNetworkSystemLocal( void ) {}

	virtual void			ServerSendReliableMessage( int clientNum, const idBitMsg &msg );
	virtual void			ServerSendReliableMessageExcluding( int clientNum, const idBitMsg &msg );
	virtual int				ServerGetClientPing( int clientNum );
	virtual int				ServerGetClientPrediction( int clientNum );
	virtual int				ServerGetClientTimeSinceLastPacket( int clientNum );
	virtual int				ServerGetClientTimeSinceLastInput( int clientNum );
	virtual int				ServerGetClientOutgoingRate( int clientNum );
	virtual int				ServerGetClientIncomingRate( int clientNum );
	virtual float			ServerGetClientIncomingPacketLoss( int clientNum );

	virtual void			ClientSendReliableMessage( const idBitMsg &msg );
	virtual int				ClientGetPrediction( void );
	virtual int				ClientGetTimeSinceLastPacket( void );
	virtual int				ClientGetOutgoingRate( void );
	virtual int				ClientGetIncomingRate( void );
	virtual float			ClientGetIncomingPacketLoss( void );
};

class idRenderSystemLocal : public idRenderSystem {
public:

	virtual					~idRenderSystemLocal() {}

	// set up cvars and basic data structures, but don't
	// init OpenGL, so it can also be used for dedicated servers
	virtual void			Init( void );

	// only called before quitting
	virtual void			Shutdown( void );

	virtual void			InitOpenGL( void );

	virtual void			ShutdownOpenGL( void );

	virtual bool			IsOpenGLRunning( void ) const;

	virtual bool			IsFullScreen( void ) const;
	virtual int				GetScreenWidth( void ) const;
	virtual int				GetScreenHeight( void ) const;

	// allocate a renderWorld to be used for drawing
	virtual idRenderWorld *	AllocRenderWorld( void );
	virtual	void			FreeRenderWorld( idRenderWorld * rw );

	// All data that will be used in a level should be
	// registered before rendering any frames to prevent disk hits,
	// but they can still be registered at a later time
	// if necessary.
	virtual void			BeginLevelLoad( void );
	virtual void			EndLevelLoad( void );

	// font support
	virtual bool			RegisterFont( const char *fontName, fontInfoEx_t &font );

	// GUI drawing just involves shader parameter setting and axial image subsections
	virtual void			SetColor( const idVec4 &rgba );
	virtual void			SetColor4( float r, float g, float b, float a );

	virtual void			DrawStretchPic( const idDrawVert *verts, const glIndex_t *indexes, int vertCount, int indexCount, const idMaterial *material,
											bool clip = true, float min_x = 0.0f, float min_y = 0.0f, float max_x = 640.0f, float max_y = 480.0f );
	virtual void			DrawStretchPic( float x, float y, float w, float h, float s1, float t1, float s2, float t2, const idMaterial *material );

	virtual void			DrawStretchTri ( idVec2 p1, idVec2 p2, idVec2 p3, idVec2 t1, idVec2 t2, idVec2 t3, const idMaterial *material );
	virtual void			GlobalToNormalizedDeviceCoordinates( const idVec3 &global, idVec3 &ndc );
	virtual void			GetGLSettings( int& width, int& height );
	virtual void			PrintMemInfo( MemInfo_t *mi );

	virtual void			DrawSmallChar( int x, int y, int ch, const idMaterial *material );
	virtual void			DrawSmallStringExt( int x, int y, const char *string, const idVec4 &setColor, bool forceColor, const idMaterial *material );
	virtual void			DrawBigChar( int x, int y, int ch, const idMaterial *material );
	virtual void			DrawBigStringExt( int x, int y, const char *string, const idVec4 &setColor, bool forceColor, const idMaterial *material );

	// dump all 2D drawing so far this frame to the demo file
	virtual void			WriteDemoPics();

	// draw the 2D pics that were saved out with the current demo frame
	virtual void			DrawDemoPics();

	// FIXME: add an interface for arbitrary point/texcoord drawing


	// a frame cam consist of 2D drawing and potentially multiple 3D scenes
	// window sizes are needed to convert SCREEN_WIDTH / SCREEN_HEIGHT values
	virtual void			BeginFrame( int windowWidth, int windowHeight );

	// if the pointers are not NULL, timing info will be returned
	virtual void			EndFrame( int *frontEndMsec, int *backEndMsec );

	// aviDemo uses this.
	// Will automatically tile render large screen shots if necessary
	// Samples is the number of jittered frames for anti-aliasing
	// If ref == NULL, session->updateScreen will be used
	// This will perform swapbuffers, so it is NOT an approppriate way to
	// generate image files that happen during gameplay, as for savegame
	// markers.  Use WriteRender() instead.
	virtual void			TakeScreenshot( int width, int height, const char *fileName, int samples, struct renderView_s *ref );

	// the render output can be cropped down to a subset of the real screen, as
	// for save-game reviews and split-screen multiplayer.  Users of the renderer
	// will not know the actual pixel size of the area they are rendering to

	// the x,y,width,height values are in virtual SCREEN_WIDTH / SCREEN_HEIGHT coordinates

	// to render to a texture, first set the crop size with makePowerOfTwo = true,
	// then perform all desired rendering, then capture to an image
	// if the specified physical dimensions are larger than the current cropped region, they will be cut down to fit
	virtual void			CropRenderSize( int width, int height, bool makePowerOfTwo = false, bool forceDimensions = false );
	virtual void			CaptureRenderToImage( const char *imageName );
	// fixAlpha will set all the alpha channel values to 0xff, which allows screen captures
	// to use the default tga loading code without having dimmed down areas in many places
	virtual void			CaptureRenderToFile( const char *fileName, bool fixAlpha = false );
	virtual void			UnCrop();
	virtual void			GetCardCaps( bool &oldCard, bool &nv10or20 );

	// the image has to be already loaded ( most straightforward way would be through a FindMaterial )
	// texture filter / mipmapping / repeat won't be modified by the upload
	// returns false if the image wasn't found
	virtual bool			UploadImage( const char *imageName, const byte *data, int width, int height );
};

class idSoundSystemLocal : public idSoundSystem {
public:
	virtual					~idSoundSystemLocal( void ) {}

	// all non-hardware initialization
	virtual void			Init( void );

	// shutdown routine
	virtual	void			Shutdown( void );

	// call ClearBuffer if there is a chance that the AsyncUpdate won't get called
	// for 20+ msec, which would cause a stuttering repeat of the current
	// buffer contents
	virtual void			ClearBuffer( void );

	// sound is attached to the window, and must be recreated when the window is changed
	virtual bool			InitHW( void );
	virtual bool			ShutdownHW( void );

	// asyn loop, called at 60Hz
	virtual int				AsyncUpdate( int time );

	// async loop, when the sound driver uses a write strategy
	virtual int				AsyncUpdateWrite( int time );

	// it is a good idea to mute everything when starting a new level,
	// because sounds may be started before a valid listener origin
	// is specified
	virtual void			SetMute( bool mute );

	// for the sound level meter window
	virtual cinData_t		ImageForTime( const int milliseconds, const bool waveform );

	// get sound decoder info
	virtual int				GetSoundDecoderInfo( int index, soundDecoderInfo_t &decoderInfo );

	// if rw == NULL, no portal occlusion or rendered debugging is available
	virtual idSoundWorld *	AllocSoundWorld( idRenderWorld *rw );

	// specifying NULL will cause silence to be played
	virtual void			SetPlayingSoundWorld( idSoundWorld *soundWorld );

	// some tools, like the sound dialog, may be used in both the game and the editor
	// This can return NULL, so check!
	virtual idSoundWorld *	GetPlayingSoundWorld( void );

	// Mark all soundSamples as currently unused,
	// but don't free anything.
	virtual	void			BeginLevelLoad( void );

	// Free all soundSamples marked as unused
	// We might want to defer the loading of new sounds to this point,
	// as we do with images, to avoid having a union in memory at one time.
	virtual	void			EndLevelLoad( const char *mapString );

	// direct mixing for OSes that support it
	virtual int				AsyncMix( int soundTime, float *mixBuffer );

	// prints memory info
	virtual void			PrintMemInfo( MemInfo_t *mi );

	// is EAX support present - -1: disabled at compile time, 0: no suitable hardware, 1: ok, 2: failed to load OpenAL DLL
	virtual int				IsEAXAvailable( void );
};

class idRenderModelManagerLocal : public idRenderModelManager {
public:
	virtual					~idRenderModelManagerLocal() {}

	// registers console commands and clears the list
	virtual	void			Init();

	// frees all the models
	virtual	void			Shutdown();

	// called only by renderer::BeginLevelLoad
	virtual void			BeginLevelLoad();

	// called only by renderer::EndLevelLoad
	virtual void			EndLevelLoad();

	// allocates a new empty render model.
	virtual idRenderModel *	AllocModel();

	// frees a render model
	virtual void			FreeModel( idRenderModel *model );

	// returns NULL if modelName is NULL or an empty string, otherwise
	// it will create a default model if not loadable
	virtual	idRenderModel *	FindModel( const char *modelName );

	// returns NULL if not loadable
	virtual	idRenderModel *	CheckModel( const char *modelName );

	// returns the default cube model
	virtual	idRenderModel *	DefaultModel();

	// world map parsing will add all the inline models with this call
	virtual	void			AddModel( idRenderModel *model );

	// when a world map unloads, it removes its internal models from the list
	// before freeing them.
	// There may be an issue with multiple renderWorlds that share data...
	virtual	void			RemoveModel( idRenderModel *model );

	// the reloadModels console command calls this, but it can
	// also be explicitly invoked
	virtual	void			ReloadModels( bool forceAll = false );

	// write "touchModel <model>" commands for each non-world-map model
	virtual	void			WritePrecacheCommands( idFile *f );

	// called during vid_restart
	virtual	void			FreeModelVertexCaches();

	// print memory info
	virtual	void			PrintMemInfo( MemInfo_t *mi );
};

class idUserInterfaceManagerLocal : public idUserInterfaceManager {
public:
	virtual						~idUserInterfaceManagerLocal( void ) {};

	virtual void				Init();
	virtual void				Shutdown();
	virtual void				Touch( const char *name );
	virtual void				WritePrecacheCommands( idFile *f );

								// Sets the size for 640x480 adjustment.
	virtual void				SetSize( float width, float height );

	virtual void				BeginLevelLoad();
	virtual void				EndLevelLoad();

								// Reloads changed guis, or all guis.
	virtual void				Reload( bool all );

								// lists all guis
	virtual void				ListGuis() const;

								// Returns true if gui exists.
	virtual bool				CheckGui( const char *qpath ) const;

								// Allocates a new gui.
	virtual idUserInterface *	Alloc( void ) const;

								// De-allocates a gui.. ONLY USE FOR PRECACHING
	virtual void				DeAlloc( idUserInterface *gui );

								// Returns NULL if gui by that name does not exist.
	virtual idUserInterface *	FindGui( const char *qpath, bool autoLoad = false, bool needUnique = false, bool forceUnique = false );

								// Returns NULL if gui by that name does not exist.
	virtual idUserInterface *	FindDemoGui( const char *qpath );

								// Allocates a new GUI list handler
	virtual	idListGUI *			AllocListGUI( void ) const;

								// De-allocates a list gui
	virtual void				FreeListGUI( idListGUI *listgui );
};

class idDeclManagerLocal : public idDeclManager {
public:
	virtual					~idDeclManagerLocal( void ) {}

	virtual void			Init( void );
	virtual void			Shutdown( void );
	virtual void			Reload( bool force );

	virtual void			BeginLevelLoad();
	virtual void			EndLevelLoad();

							// Registers a new decl type.
	virtual void			RegisterDeclType( const char *typeName, declType_t type, idDecl *(*allocator)( void ) );

							// Registers a new folder with decl files.
	virtual void			RegisterDeclFolder( const char *folder, const char *extension, declType_t defaultType );

							// Returns a checksum for all loaded decl text.
	virtual int				GetChecksum( void ) const;

							// Returns the number of decl types.
	virtual int				GetNumDeclTypes( void ) const;

							// Returns the type name for a decl type.
	virtual const char *	GetDeclNameFromType( declType_t type ) const;

							// Returns the decl type for a type name.
	virtual declType_t		GetDeclTypeFromName( const char *typeName ) const;

							// If makeDefault is true, a default decl of appropriate type will be created
							// if an explicit one isn't found. If makeDefault is false, NULL will be returned
							// if the decl wasn't explcitly defined.
	virtual const idDecl *	FindType( declType_t type, const char *name, bool makeDefault = true );

	virtual const idDecl*	FindDeclWithoutParsing( declType_t type, const char *name, bool makeDefault = true );

	virtual void			ReloadFile( const char* filename, bool force );

							// Returns the number of decls of the given type.
	virtual int				GetNumDecls( declType_t type );

							// The complete lists of decls can be walked to populate editor browsers.
							// If forceParse is set false, you can get the decl to check name / filename / etc.
							// without causing it to parse the source and load media.
	virtual const idDecl *	DeclByIndex( declType_t type, int index, bool forceParse = true );

							// List and print decls.
	virtual void			ListType( const idCmdArgs &args, declType_t type );
	virtual void			PrintType( const idCmdArgs &args, declType_t type );

							// Creates a new default decl of the given type with the given name in
							// the given file used by editors to create a new decls.
	virtual idDecl *		CreateNewDecl( declType_t type, const char *name, const char *fileName );

							// BSM - Added for the material editors rename capabilities
	virtual bool			RenameDecl( declType_t type, const char* oldName, const char* newName );

							// When media files are loaded, a reference line can be printed at a
							// proper indentation if decl_show is set
	virtual void			MediaPrint( const char *fmt, ... ) id_attribute((format(printf,2,3)));

	virtual void			WritePrecacheCommands( idFile *f );

									// Convenience functions for specific types.
	virtual	const idMaterial *		FindMaterial( const char *name, bool makeDefault = true );
	virtual const idDeclSkin *		FindSkin( const char *name, bool makeDefault = true );
	virtual const idSoundShader *	FindSound( const char *name, bool makeDefault = true );

	virtual const idMaterial *		MaterialByIndex( int index, bool forceParse = true );
	virtual const idDeclSkin *		SkinByIndex( int index, bool forceParse = true );
	virtual const idSoundShader *	SoundByIndex( int index, bool forceParse = true );
};

class idAASFileManagerLocal : public idAASFileManager {
public:
	virtual						~idAASFileManagerLocal( void ) {}

	virtual idAASFile *			LoadAAS( const char *fileName, unsigned int mapFileCRC );
	virtual void				FreeAAS( idAASFile *file );
};

class idCollisionModelManagerLocal : public idCollisionModelManager {
public:
	virtual					~idCollisionModelManagerLocal( void ) {}

	// Loads collision models from a map file.
	virtual void			LoadMap( const idMapFile *mapFile );
	// Frees all the collision models.
	virtual void			FreeMap( void );

	// Gets the clip handle for a model.
	virtual cmHandle_t		LoadModel( const char *modelName, const bool precache );
	// Sets up a trace model for collision with other trace models.
	virtual cmHandle_t		SetupTrmModel( const idTraceModel &trm, const idMaterial *material );
	// Creates a trace model from a collision model, returns true if succesfull.
	virtual bool			TrmFromModel( const char *modelName, idTraceModel &trm );

	// Gets the name of a model.
	virtual const char *	GetModelName( cmHandle_t model ) const;
	// Gets the bounds of a model.
	virtual bool			GetModelBounds( cmHandle_t model, idBounds &bounds ) const;
	// Gets all contents flags of brushes and polygons of a model ored together.
	virtual bool			GetModelContents( cmHandle_t model, int &contents ) const;
	// Gets a vertex of a model.
	virtual bool			GetModelVertex( cmHandle_t model, int vertexNum, idVec3 &vertex ) const;
	// Gets an edge of a model.
	virtual bool			GetModelEdge( cmHandle_t model, int edgeNum, idVec3 &start, idVec3 &end ) const;
	// Gets a polygon of a model.
	virtual bool			GetModelPolygon( cmHandle_t model, int polygonNum, idFixedWinding &winding ) const;

	// Translates a trace model and reports the first collision if any.
	virtual void			Translation( trace_t *results, const idVec3 &start, const idVec3 &end,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis );
	// Rotates a trace model and reports the first collision if any.
	virtual void			Rotation( trace_t *results, const idVec3 &start, const idRotation &rotation,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis );
	// Returns the contents touched by the trace model or 0 if the trace model is in free space.
	virtual int				Contents( const idVec3 &start,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis );
	// Stores all contact points of the trace model with the model, returns the number of contacts.
	virtual int				Contacts( contactInfo_t *contacts, const int maxContacts, const idVec3 &start, const idVec6 &dir, const float depth,
								const idTraceModel *trm, const idMat3 &trmAxis, int contentMask,
								cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis );

	// Tests collision detection.
	virtual void			DebugOutput( const idVec3 &origin );
	// Draws a model.
	virtual void			DrawModel( cmHandle_t model, const idVec3 &modelOrigin, const idMat3 &modelAxis,
												const idVec3 &viewOrigin, const float radius );
	// Prints model information, use -1 handle for accumulated model info.
	virtual void			ModelInfo( cmHandle_t model );
	// Lists all loaded models.
	virtual void			ListModels( void );
	// Writes a collision model file for the given map entity.
	virtual bool			WriteCollisionModelForMapEntity( const idMapEntity *mapEnt, const char *filename, const bool testTraceModel = true );
};

extern gameImport_t importLocal;

#endif
