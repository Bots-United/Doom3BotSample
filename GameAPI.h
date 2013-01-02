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

#ifndef DLLAPI_H
#define DLLAPI_H

class idGameInterface : public idGame {
public:
	idGameInterface();
	virtual						~idGameInterface();

	// Initialize the game for the first time.
	virtual void				Init( void );

	// Shut down the entire game.
	virtual void				Shutdown( void );

	// Set the local client number. Distinguishes listen ( == 0 ) / dedicated ( == -1 )
	virtual void				SetLocalClient( int clientNum );

	// Sets the user info for a client.
	// if canModify is true, the game can modify the user info in the returned dictionary pointer, server will forward the change back
	// canModify is never true on network client
	virtual const idDict *		SetUserInfo( int clientNum, const idDict &userInfo, bool isClient, bool canModify );

	// Retrieve the game's userInfo dict for a client.
	virtual const idDict *		GetUserInfo( int clientNum );

	// The game gets a chance to alter userinfo before they are emitted to server.
	virtual void				ThrottleUserInfo( void );

	// Sets the serverinfo at map loads and when it changes.
	virtual void				SetServerInfo( const idDict &serverInfo );

	// The session calls this before moving the single player game to a new level.
	virtual const idDict &		GetPersistentPlayerInfo( int clientNum );

	// The session calls this right before a new level is loaded.
	virtual void				SetPersistentPlayerInfo( int clientNum, const idDict &playerInfo );

	// Loads a map and spawns all the entities.
	virtual void				InitFromNewMap( const char *mapName, idRenderWorld *renderWorld, idSoundWorld *soundWorld, bool isServer, bool isClient, int randseed );

	// Loads a map from a savegame file.
	virtual bool				InitFromSaveGame( const char *mapName, idRenderWorld *renderWorld, idSoundWorld *soundWorld, idFile *saveGameFile );

	// Saves the current game state, the session may have written some data to the file already.
	virtual void				SaveGame( idFile *saveGameFile );

	// Shut down the current map.
	virtual void				MapShutdown( void );

	// Caches media referenced from in key/value pairs in the given dictionary.
	virtual void				CacheDictionaryMedia( const idDict *dict );

	// Spawns the player entity to be used by the client.
	virtual void				SpawnPlayer( int clientNum );

	// Runs a game frame, may return a session command for level changing, etc
	virtual gameReturn_t		RunFrame( const usercmd_t *clientCmds );

	// Makes rendering and sound system calls to display for a given clientNum.
	virtual bool				Draw( int clientNum );

	// Let the game do it's own UI when ESCAPE is used
	virtual escReply_t			HandleESC( idUserInterface **gui );

	// get the games menu if appropriate ( multiplayer )
	virtual idUserInterface *	StartMenu();

	// When the game is running it's own UI fullscreen, GUI commands are passed through here
	// return NULL once the fullscreen UI mode should stop, or "main" to go to main menu
	virtual const char *		HandleGuiCommands( const char *menuCommand );

	// main menu commands not caught in the engine are passed here
	virtual void				HandleMainMenuCommands( const char *menuCommand, idUserInterface *gui );

	// Early check to deny connect.
	virtual allowReply_t		ServerAllowClient( int numClients, const char *IP, const char *guid, const char *password, char reason[MAX_STRING_CHARS] );

	// Connects a client.
	virtual void				ServerClientConnect( int clientNum, const char *guid );

	// Spawns the player entity to be used by the client.
	virtual void				ServerClientBegin( int clientNum );

	// Disconnects a client and removes the player entity from the game.
	virtual void				ServerClientDisconnect( int clientNum );

	// Writes initial reliable messages a client needs to recieve when first joining the game.
	virtual void				ServerWriteInitialReliableMessages( int clientNum );

	// Writes a snapshot of the server game state for the given client.
	virtual void				ServerWriteSnapshot( int clientNum, int sequence, idBitMsg &msg, byte *clientInPVS, int numPVSClients );

	// Patches the network entity states at the server with a snapshot for the given client.
	virtual bool				ServerApplySnapshot( int clientNum, int sequence );

	// Processes a reliable message from a client.
	virtual void				ServerProcessReliableMessage( int clientNum, const idBitMsg &msg );

	// Reads a snapshot and updates the client game state.
	virtual void				ClientReadSnapshot( int clientNum, int sequence, const int gameFrame, const int gameTime, const int dupeUsercmds, const int aheadOfServer, const idBitMsg &msg );

	// Patches the network entity states at the client with a snapshot.
	virtual bool				ClientApplySnapshot( int clientNum, int sequence );

	// Processes a reliable message from the server.
	virtual void				ClientProcessReliableMessage( int clientNum, const idBitMsg &msg );

	// Runs prediction on entities at the client.
	virtual gameReturn_t		ClientPrediction( int clientNum, const usercmd_t *clientCmds, bool lastPredictFrame );

	// Used to manage divergent time-lines
	virtual void				SelectTimeGroup( int timeGroup );
	virtual int					GetTimeGroupTime( int timeGroup );

	virtual void				GetBestGameType( const char* map, const char* gametype, char buf[ MAX_STRING_CHARS ] );

	// Returns a summary of stats for a given client
	virtual void				GetClientStats( int clientNum, char *data, const int len );

	// Switch a player to a particular team
	virtual void				SwitchTeam( int clientNum, int team );

	virtual bool				DownloadRequest( const char *IP, const char *guid, const char *paks, char urls[ MAX_STRING_CHARS ] );

	virtual void				GetMapLoadingGUI( char gui[ MAX_STRING_CHARS ] );
};

extern idGameInterface gameInterface;

#endif
