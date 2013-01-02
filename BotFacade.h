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

#ifndef BOTFACADE_H
#define BOTFACADE_H

class idBotCommon;
class idBotService;
class idBot;

#define MAX_BOTS	32

class idBotFacade {
public:
	static bool				BotInit();
	static void				BotShutdown();

	static void				BotStartFrame();

	static void				UpdateBotClientCmds( usercmd_t *clientCmds );

	static void				AddBot( const char *botName );
	static void				KickBot( const char *botName );
	static void				KickBot( int botIndex );

	static inline bool		IsBot( int clientNum );
	static inline idBot *	GetBotHandle( int clientNum );

private:
	static idBotCommon *	botCommon;
	static idBotService *	botService;

	static idBot *			bots[ MAX_BOTS ];

	static int				nextThinkTime;
};

bool idBotFacade::IsBot( int clientNum ) {
	if ( clientNum >= MAX_BOTS ) {
		return false; // relibility check
	}
	return bots[ clientNum ] != NULL;
}

idBot *idBotFacade::GetBotHandle( int clientNum ) {
	if ( clientNum >= MAX_BOTS ) {
		return NULL; // relibility check
	}
	return bots[ clientNum ];
}

#endif
