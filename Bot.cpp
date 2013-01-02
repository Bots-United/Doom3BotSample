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

/*
================
idBot::Factory

  Create mod-dependant bot instance.
================
*/
idBot *idBot::Factory( int clientNum, const idDict *botProfile ) {
	idBot *bot = NULL;

	const char *game = cvarSystem->GetCVarString( "fs_game" );
	if ( strlen( game ) == 0 ) {
		game = BASE_GAMEDIR;
	}

	if ( idStr::Cmp( game, BASE_GAMEDIR ) == 0 ) {
		bot = new idBot_D3;
	}

	if ( !bot ) {
		return NULL;
	}

	bot->clientNum = clientNum;
	bot->ProcessBotProfile( botProfile );

	return bot;
}

/*
================
idBot::GetOrigin

  Get the origin of the bot.
================
*/
const idVec3 &idBot::GetOrigin( void ) {
	return gameAdapter->EntityOrigin( Entity() );
}

/*
================
idBot::GetEyePosition

  Get the eye position of the bot.
================
*/
idVec3 idBot::GetEyePosition( void ) {
	return gameAdapter->EntityEyePosition( Entity() );
}
