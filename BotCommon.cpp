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

idBotCommon::idBotCommon() {
	LoadBotProfile();
}

idBotCommon::~idBotCommon() {
}

int idBotCommon::CreateFakeClient( const idDict &botUserInfo ) {
	int clientNum;
	const char *guid = NULL;

	clientNum = gameAdapter->GetFreeClientSlot();
	if ( clientNum == -1 ) {
		common->Warning( "Max. Players reached.  Can't create bot!" );
		return -1;
	}

	// Start up client
	game->ServerClientConnect( clientNum, guid );
	game->ServerClientBegin( clientNum );

	game->SetUserInfo( clientNum, botUserInfo, false, true );
	cmdSystem->BufferCommandText( CMD_EXEC_NOW, va( "updateUI %d\n", clientNum ) );

	// Success!, return its client num.
	return clientNum;
}

const idDict *idBotCommon::PickBotProfile( const char *botName ) {
	if ( botProfiles.Num() <= 0 ) {
		return NULL; // no bot profiles
	}

	if ( !botName ) {
		// not bot name provided, pick a random profile
		return &botProfiles[ gameAdapter->Random()->RandomInt( botProfiles.Num() ) ];
	}

	for ( int i = 0; i < botProfiles.Num(); ++i ) {
		if ( idStr::Cmp( botProfiles[ i ].GetString( "name" ), botName ) == 0 ) {
			return &botProfiles[ i ];
		}
	}

	return NULL; // not found
}

void idBotCommon::LoadBotProfile( void ) {
	botProfiles.Clear();

	// list all bot profiles
	idFileList *botList = fileSystem->ListFiles( "bots", "cfg", true, true );

	if ( !botList ) {
		return;
	}

	int botNum = botList->GetNumFiles();

	for ( int i = 0; i < botNum; i++ ) {
		// use idDict rather than a simple struct for extensibility
		idDict botProfile;
		idParser parser;

		// read the file
		if ( !parser.LoadFile( botList->GetFile( i ) ) ) {
			continue;
		}

		idToken token, valueToken;
		bool begin = false;

		while ( parser.ReadToken( &token ) ) {
			if ( !begin ) {
				if ( token.Cmp( "{" ) == 0 ) {
					begin = true;
				}
				continue;
			}

			if ( token.Cmp( "}" ) == 0 ) {
				break;
			}

			if ( !parser.ReadToken( &valueToken ) || valueToken.Cmp( "}" ) == 0 ) {
				break;
			}

			botProfile.Set( token.c_str(), valueToken.c_str() );
		}

		// add the profile only if the profile contains a name
		if ( botProfile.GetString( "name" )[0] != '\0' ) {
			common->Printf( "Loaded bot profile: '%s'.\n", botProfile.GetString( "name" ) );
			botProfiles.Append( botProfile );
		}
	}

	fileSystem->FreeFileList( botList );
}
