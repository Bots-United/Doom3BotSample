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

idGameInterface gameInterface;

void UnloadGameDLL( void );

idGameInterface::idGameInterface() {
	// initialize idLib
	idLib::Init();
}

idGameInterface::~idGameInterface() {
	UnloadGameDLL();

	// shutdown idLib
	idLib::ShutDown();
}

void idGameInterface::Init() {
	InitConsoleCommands(); // initialize console commands
	InitGameAdapter(); // initial game adapter

	game->Init();
}

void idGameInterface::Shutdown() {
	ShutdownGameAdapter(); // shutdown game adapter

	game->Shutdown();
}

void idGameInterface::SetLocalClient( int clientNum ) {
	game->SetLocalClient( clientNum );
}

const idDict *idGameInterface::SetUserInfo( int clientNum, const idDict &userInfo, bool isClient, bool canModify ) {
	return game->SetUserInfo( clientNum, userInfo, isClient, canModify );
}

const idDict *idGameInterface::GetUserInfo( int clientNum ) {
	return game->GetUserInfo( clientNum );
}

void idGameInterface::ThrottleUserInfo( void ) {
	game->ThrottleUserInfo();
}

void idGameInterface::SetServerInfo( const idDict &serverInfo ) {
	game->SetServerInfo( serverInfo );
}

const idDict &idGameInterface::GetPersistentPlayerInfo( int clientNum ) {
	return game->GetPersistentPlayerInfo( clientNum );
}

void idGameInterface::SetPersistentPlayerInfo( int clientNum, const idDict &playerInfo ) {
	game->SetPersistentPlayerInfo( clientNum, playerInfo );
}

void idGameInterface::InitFromNewMap( const char *mapName, idRenderWorld *renderWorld, idSoundWorld *soundWorld, bool isServer, bool isClient, int randseed ) {
	gameRenderWorld = renderWorld;
	gameSoundWorld = soundWorld;

	// initialize the bot subsystem for server
	if ( isServer ) {
		if ( !idBotFacade::BotInit() ) {
			common->Warning( "Unable to Initialize Bot Subsystem" );
		}
	}

	game->InitFromNewMap( mapName, renderWorld, soundWorld, isServer, isClient, randseed );
}

bool idGameInterface::InitFromSaveGame( const char *mapName, idRenderWorld *renderWorld, idSoundWorld *soundWorld, idFile *saveGameFile ) {
	gameRenderWorld = renderWorld;
	gameSoundWorld = soundWorld;

	return game->InitFromSaveGame( mapName, renderWorld, soundWorld, saveGameFile );
}

void idGameInterface::SaveGame( idFile *saveGameFile ) {
	game->SaveGame( saveGameFile );
}

void idGameInterface::MapShutdown( void ) {
	idBotFacade::BotShutdown(); // shutdown bot subsystem
	game->MapShutdown();
}

void idGameInterface::CacheDictionaryMedia( const idDict *dict ) {
	game->CacheDictionaryMedia( dict );
}

void idGameInterface::SpawnPlayer( int clientNum ) {
	game->SpawnPlayer( clientNum );
}

gameReturn_t idGameInterface::RunFrame( const usercmd_t *clientCmds ) {
	if ( !gameAdapter->InCinematic() ) {
		idBotFacade::BotStartFrame(); // run the main bot routine
		idBotFacade::UpdateBotClientCmds( const_cast<usercmd_t *>( clientCmds ) ); // update client commands of bots
	}
	return game->RunFrame( clientCmds );
}

bool idGameInterface::Draw( int clientNum ) {
	return game->Draw( clientNum );
}

escReply_t idGameInterface::HandleESC( idUserInterface **gui ) {
	return game->HandleESC( gui );
}

idUserInterface *idGameInterface::StartMenu() {
	return game->StartMenu();
}

const char *idGameInterface::HandleGuiCommands( const char *menuCommand ) {
	return game->HandleGuiCommands( menuCommand );
}

void idGameInterface::HandleMainMenuCommands( const char *menuCommand, idUserInterface *gui ) {
	game->HandleMainMenuCommands( menuCommand, gui );
}

allowReply_t idGameInterface::ServerAllowClient( int numClients, const char *IP, const char *guid, const char *password, char reason[MAX_STRING_CHARS] ) {
	return game->ServerAllowClient( numClients, IP, guid, password, reason );
}

void idGameInterface::ServerClientConnect( int clientNum, const char *guid ) {
	idBotFacade::KickBot( clientNum ); // kick the bot at the same clientnum

	game->ServerClientConnect( clientNum, guid );
}

void idGameInterface::ServerClientBegin( int clientNum ) {
	// update UI for all bots
	for ( int i = 0; i < MAX_BOTS; i++ ) {
		if ( idBotFacade::IsBot( i ) ) {
			cmdSystem->BufferCommandText( CMD_EXEC_NOW, va( "updateUI %d\n", i ) );
		}
	}

	game->ServerClientBegin( clientNum );
}

void idGameInterface::ServerClientDisconnect( int clientNum ) {
	game->ServerClientDisconnect( clientNum );
}

void idGameInterface::ServerWriteInitialReliableMessages( int clientNum ) {
	game->ServerWriteInitialReliableMessages( clientNum );
}

void idGameInterface::ServerWriteSnapshot( int clientNum, int sequence, idBitMsg &msg, byte *clientInPVS, int numPVSClients ) {
	game->ServerWriteSnapshot( clientNum, sequence, msg, clientInPVS, numPVSClients );
}

bool idGameInterface::ServerApplySnapshot( int clientNum, int sequence ) {
	return game->ServerApplySnapshot( clientNum, sequence );
}

void idGameInterface::ServerProcessReliableMessage( int clientNum, const idBitMsg &msg ) {
	game->ServerProcessReliableMessage( clientNum, msg );
}

void idGameInterface::ClientReadSnapshot( int clientNum, int sequence, const int gameFrame, const int gameTime, const int dupeUsercmds, const int aheadOfServer, const idBitMsg &msg ) {
	game->ClientReadSnapshot( clientNum, sequence, gameFrame, gameTime, dupeUsercmds, aheadOfServer, msg );
}

bool idGameInterface::ClientApplySnapshot( int clientNum, int sequence ) {
	return game->ClientApplySnapshot( clientNum, sequence );
}

void idGameInterface::ClientProcessReliableMessage( int clientNum, const idBitMsg &msg ) {
	game->ClientProcessReliableMessage( clientNum, msg );
}

gameReturn_t idGameInterface::ClientPrediction( int clientNum, const usercmd_t *clientCmds, bool lastPredictFrame ) {
	return game->ClientPrediction( clientNum, clientCmds, lastPredictFrame );
}

void idGameInterface::SelectTimeGroup( int timeGroup ) {
	game->SelectTimeGroup( timeGroup );
}

int idGameInterface::GetTimeGroupTime( int timeGroup ) {
	return game->GetTimeGroupTime( timeGroup );
}

void idGameInterface::GetBestGameType( const char* map, const char* gametype, char buf[ MAX_STRING_CHARS ] ) {
	game->GetBestGameType( map, gametype, buf );
}

void idGameInterface::GetClientStats( int clientNum, char *data, const int len ) {
	game->GetClientStats( clientNum, data, len );
}

void idGameInterface::SwitchTeam( int clientNum, int team ) {
	game->SwitchTeam( clientNum, team );
}

bool idGameInterface::DownloadRequest( const char *IP, const char *guid, const char *paks, char urls[ MAX_STRING_CHARS ] ) {
	return game->DownloadRequest( IP, guid, paks, urls );
}

void idGameInterface::GetMapLoadingGUI( char gui[ MAX_STRING_CHARS ] ) {
	game->GetMapLoadingGUI( gui );
}
