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

idBotCommon		*idBotFacade::botCommon = NULL;
idBotService	*idBotFacade::botService = NULL;
idBot			*idBotFacade::bots[ MAX_BOTS ];

int				idBotFacade::nextThinkTime = 0;

bool idBotFacade::BotInit() {
	// shutdown if bot is already initialized
	BotShutdown();

	// create botcommon
	botCommon = new idBotCommon;
	if ( !botCommon ) {
		BotShutdown();
		return false;
	}

	// create botservice
	botService = idBotService::Factory();
	if ( !botService ) {
		BotShutdown();
		return false;
	}

	nextThinkTime = 0;

	return true; // success
}

void idBotFacade::BotShutdown() {
	for ( int i = 0; i < MAX_BOTS; ++i ) {
		if ( bots[ i ] ) {
			delete bots[ i ];
			bots[ i ] = NULL;
		}
	}

	if ( botCommon ) {
		delete botCommon;
		botCommon = NULL;
	}

	if ( botService ) {
		delete botService;
		botService = NULL;
	}
}

void idBotFacade::BotStartFrame() {
	int time = gameAdapter->GetTime();

	// run bot thinking routine at 10Hz
	if ( time > nextThinkTime ) {
		for ( int i = 0; i < MAX_BOTS; ++i ) {
			if ( bots[ i ] ) {
				bots[ i ]->BotThink();
			}
		}
		nextThinkTime = time + 1000 / 10;
	}
}

void idBotFacade::UpdateBotClientCmds( usercmd_t *clientCmds ) {
	for ( int i = 0; i < MAX_BOTS; ++i ) {
		if ( bots[ i ] ) {
			bots[ i ]->UpdateBotInput( &clientCmds[ i ] );
		}
	}
}

void idBotFacade::AddBot( const char *botName ) {
	const idDict *botProfile = botCommon->PickBotProfile( botName );

	if ( botProfile == NULL ) {
		common->Warning( "Unable to find bot profile for '%s'", botName );
		return;
	}

	idDict botUserInfo;

	if ( !botService->GetBotUserInfo( botProfile, &botUserInfo ) ) {
		return;
	}

	int clientIndex = botCommon->CreateFakeClient( botUserInfo );

	if ( clientIndex == -1 ) {
		return;
	}

	if ( bots[ clientIndex ] ) {
		common->Warning( "clientindex %d already has a bot", clientIndex );
		delete bots[ clientIndex ];
		bots[ clientIndex ] = NULL;
	}

	bots[ clientIndex ] = idBot::Factory( clientIndex, botProfile );

	if ( !bots[ clientIndex ] ) {
		common->Warning( "Bot creation failed" );
		return;
	}

	common->Printf( "Bot '%s' created\n", botProfile->GetString( "name" ) );
}

void idBotFacade::KickBot( const char *botName ) {
	for ( int i = 0; i < MAX_BOTS; ++i ) {
		if ( !IsBot( i ) ) {
			continue;
		}

		if ( idStr::Icmp( gameAdapter->GetPlayerName( i ), botName ) == 0 ) {
			KickBot( i );
			break;
		}
	}
}

void idBotFacade::KickBot( int clientIndex ) {
	if ( !IsBot( clientIndex ) ) {
		return;
	}

	char buf[ 64 ];
	idStr::Copynz( buf, gameAdapter->GetPlayerName( clientIndex ), sizeof( buf ) );

	game->ServerClientDisconnect( clientIndex );

	delete bots[ clientIndex ];
	bots[ clientIndex ] = NULL;

	common->Printf( "Bot '%s' kicked\n", buf );
}
