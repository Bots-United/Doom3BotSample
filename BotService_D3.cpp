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
#include "../game/Game_local.h"

static const char *si_gameTypeArgs[]		= { "singleplayer", "deathmatch", "Tourney", "Team DM", "Last Man", NULL };
static const char *si_readyArgs[]			= { "Not Ready", "Ready", NULL }; 
static const char *si_spectateArgs[]		= { "Play", "Spectate", NULL };

static const char *ui_skinArgs[]			= { "skins/characters/player/marine_mp",
												"skins/characters/player/marine_mp_red",
												"skins/characters/player/marine_mp_blue",
												"skins/characters/player/marine_mp_green",
												"skins/characters/player/marine_mp_yellow",
												NULL };

static const char *ui_teamArgs[]			= { "Red", "Blue", NULL }; 

bool idBotService_D3::GetBotUserInfo( const idDict *botProfile, idDict *botUserInfo ) {
	if ( botProfile == NULL || botUserInfo == NULL ) {
		return false; // reliability check
	}

	botUserInfo->Clear();

	const char *botName = botProfile->GetString( "name" );
	if ( !botName[0] ) {
		return false;
	}

	botUserInfo->Set( "ui_name",  botProfile->GetString( "ui_name", botName ) );
	botUserInfo->Set( "name", botName );

	const char *botSkin = botProfile->GetString( "model" );
	if ( !botSkin[0] ) {
		botSkin = ui_skinArgs[ gameAdapter->Random()->RandomInt( sizeof( ui_skinArgs ) / sizeof( ui_skinArgs[0] ) - 1 ) ];
	}

	botUserInfo->Set( "ui_skin", botSkin );

	botUserInfo->Set( "ui_hitscanTint", "120 0.6 1" );
	botUserInfo->Set( "ui_autoSwitch", "0" );
	botUserInfo->Set( "ui_autoReload", "0" );
	botUserInfo->Set( "ui_showGun", "1" );

	botUserInfo->Set( "ui_ready", "Ready" );

	idGameAdapter_D3 *gameAdapter_D3 = dynamic_cast<idGameAdapter_D3 *>( gameAdapter );

	if ( gameAdapter_D3 && gameAdapter_D3->IsTeamplay() ) {
		const char *botTeam = botProfile->GetString( "team" );
		if ( botTeam[0] ) {
			botUserInfo->Set( "ui_team", botTeam );
		}
	}

	botUserInfo->SetBool( "bot", true );
	return true;
}
