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

/////////////////////////////////////////////////////////////
//          C O N S O L E       C O M M A N D S            //
/////////////////////////////////////////////////////////////

void Cmd_Bot_ShowHelp( const idCmdArgs &args ) {
	// display the help message
	common->Printf( "*** Bot Prototype (%s) *** \n", __DATE__ );
	common->Printf( "bot add <name> - Create a bot.\n" );
	common->Printf( "bot kick <name> - Kick a bot.\n" );
	common->Printf( "bot help - Show this message.\n" );
}

void Cmd_Bot_AddBot( const idCmdArgs &args ) {
	if ( args.Argc() != 2 && args.Argc() != 3 ) {
		common->Printf( "usage: bot add <name>\n" );
		return;
	}
	idBotFacade::AddBot( ( args.Argc() == 3 ) ? args.Argv( 2 ) : NULL );
}

void Cmd_Bot_KickBot( const idCmdArgs &args ) {
	if ( args.Argc() != 3 ) {
		common->Printf( "usage: bot kick <name>\n" );
		return;
	}

	idBotFacade::KickBot( args.Argv( 2 ) ); // kick bot by name
}

// console command structure definition
typedef struct {
	const char *szCmd;     // command name
	void ( *pFunc ) ( const idCmdArgs &args );  // function to execute this command
	bool fInGame;          // whether we need to be in game or not
} consoleCmd_t;

// list of console commands
static consoleCmd_t commands[] = {
	{ "help",		Cmd_Bot_ShowHelp,		false },
	{ "add",		Cmd_Bot_AddBot,			true },
	{ "kick",		Cmd_Bot_KickBot,		true },
	{ NULL, NULL, false } // terminator
};

// This is the real function to handle the console commands.
static void Cmd_Bot_f( const idCmdArgs &args ) {
	if ( args.Argc() == 1 ) {
		common->Printf( "usage: bot <command> <parameters>\n" );
		common->Printf( "type 'bot help' for more information\n" );
		return;
	}

	const char *cmd = args.Argv( 1 );
	consoleCmd_t *pCommand = commands;

	while ( pCommand->szCmd ) {
		if ( idStr::Icmp( cmd, pCommand->szCmd ) == 0 ) {
			// make sure the game has started if we need
			if ( !pCommand->fInGame || ( gameAdapter->IsMultiplayer() && gameAdapter->IsServer() ) )
				pCommand->pFunc( args );
			else
				common->Printf( "BOT: cannot '%s', server is not running\n", cmd );
			return;
		}
		pCommand++;
	}

	common->Printf( "BOT: Unknown command. Type 'bot help' for more info.\n" );
}

void InitConsoleCommands( void ) {
	cmdSystem->AddCommand( "bot", Cmd_Bot_f, CMD_FL_GAME, "Invoke bot commands" );
}
