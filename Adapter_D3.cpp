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

// we need access to all class members
#define private public
#define protected public

#include "../game/Game_local.h"

idGameAdapter_D3::idGameAdapter_D3() {
}

idGameAdapter_D3::~idGameAdapter_D3() {
}

int idGameAdapter_D3::GetNumClients( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return gameLocal->numClients;
}

int idGameAdapter_D3::GetFreeClientSlot( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);

	int maxPlayers = ServerInfo()->GetInt( "si_maxPlayers" );
	int numPlayers = 0;
	int i;

	// count the number of players
	for ( i = 0; i < MAX_CLIENTS; ++i ) {
		if ( gameLocal->entities[ i ] ) {
			++numPlayers;
		}
	}

	if ( numPlayers >= maxPlayers ) {
		return -1;
	}

	// search backwards for a free client slot
	for ( i = MAX_CLIENTS - 1; i >= 0; --i ) {
		if ( !gameLocal->entities[i] ) {
			return i;
		}
	}

	return -1; // no free client slot
}

bool idGameAdapter_D3::IsMultiplayer( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return gameLocal->isMultiplayer;
}

bool idGameAdapter_D3::IsServer( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return gameLocal->isServer;
}

bool idGameAdapter_D3::InCinematic( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return gameLocal->inCinematic;
}

idDict *idGameAdapter_D3::ServerInfo( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return &gameLocal->serverInfo;
}

int idGameAdapter_D3::GetTime( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return gameLocal->time;
}

idDict *idGameAdapter_D3::UserInfo( int clientNum ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	if ( clientNum >= MAX_CLIENTS ) {
		return NULL;
	}
	return &gameLocal->userInfo[ clientNum ];
}

usercmd_t *idGameAdapter_D3::UserCmd( int clientNum ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	if ( clientNum >= MAX_CLIENTS ) {
		return NULL;
	}
	return &gameLocal->usercmds[ clientNum ];
}

idRandom *idGameAdapter_D3::Random( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return &gameLocal->random;
}

idPVS *idGameAdapter_D3::PVS( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return &gameLocal->pvs;
}

idClip *idGameAdapter_D3::Clip( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return &gameLocal->clip;
}

idEntity *idGameAdapter_D3::Entity( int entityNum ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);

	if ( entityNum < 0 || entityNum >= MAX_GENTITIES ) {
		return NULL; // reliability check
	}

	return gameLocal->entities[ entityNum ];
}

const idStr &idGameAdapter_D3::EntityName( const idEntity *ent ) {
	return ent->name;
}

const idDict &idGameAdapter_D3::EntitySpawnArgs( const idEntity *ent ) {
	return ent->spawnArgs;
}

const idVec3 &idGameAdapter_D3::EntityOrigin( const idEntity *ent ) {
	return ent->physics->GetOrigin();
}

const idVec3 &idGameAdapter_D3::EntityVelocity( const idEntity *ent ) {
	return ent->physics->GetLinearVelocity();
}

const idBounds &idGameAdapter_D3::EntityBounds( const idEntity *ent ) {
	return ent->physics->GetBounds();
}

const idBounds &idGameAdapter_D3::EntityAbsBounds( const idEntity *ent ) {
	return ent->physics->GetAbsBounds();
}

idVec3 idGameAdapter_D3::EntityEyePosition( const idEntity *ent ) {
	// use run-time casting to check if this entity is a player...
	const idPlayer *player = dynamic_cast<const idPlayer *>( ent );
	if ( player ) {
		// return eye position of the player
		return ent->physics->GetOrigin() + ( ent->physics->GetGravityNormal() * -player->eyeOffset.z );
	} else {
		// just return the origin for non-player entities
		return ent->physics->GetOrigin();
	}
}

const char *idGameAdapter_D3::GetPlayerName( int clientNum ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);

	if( clientNum < 0 || clientNum >= MAX_CLIENTS || !gameLocal->entities[ clientNum ] ) {
		return NULL; // reliability check
	}

	return UserInfo( clientNum )->GetString( "ui_name" );
}

bool idGameAdapter_D3::IsTeamplay( void ) {
	idGameLocal *gameLocal = static_cast<idGameLocal *>(game);
	return ( IsMultiplayer() && ( gameLocal->gameType == GAME_TDM ) );
}
