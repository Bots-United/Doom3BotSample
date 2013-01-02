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

idGameAdapter *gameAdapter = NULL;

idGameAdapter *idGameAdapter::Factory( void ) {
	const char *game = cvarSystem->GetCVarString( "fs_game" );
	if ( strlen( game ) == 0 ) {
		game = BASE_GAMEDIR;
	}

	if ( idStr::Cmp( game, BASE_GAMEDIR ) == 0 ) {
		return new idGameAdapter_D3;
	}

	return NULL; // unknown mod
}

void InitGameAdapter( void ) {
	gameAdapter = idGameAdapter::Factory();

	if ( !gameAdapter ) {
		common->FatalError( "Failed to create GameAdapter" );
	}
}

void ShutdownGameAdapter( void ) {
	if ( gameAdapter ) {
		delete gameAdapter;
	}
	gameAdapter = NULL;
}
