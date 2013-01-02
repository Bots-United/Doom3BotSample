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

idBot_D3::idBot_D3() {
	snapshotSequence = 1;
	memset( clientInPVS, 0, sizeof( clientInPVS ) );
	health = 0;
	armor = 0;
	weapons = 0;
	memset( ammo, 0, sizeof( ammo ) );
	memset( clip, 0, sizeof( clip ) );

	prevOrigin.Zero();
}

idBot_D3::~idBot_D3() {
}

void idBot_D3::BotThink() {
	UpdateBotState();

	BotFindEnemy();
	prevOrigin = GetOrigin();
}

void idBot_D3::UpdateBotInput( usercmd_t *clientCmd ) {
	memset( clientCmd, 0, sizeof( usercmd_t ) );

	clientCmd->forwardmove = 127;
//	clientCmd->rightmove = gameAdapter->Random()->RandomInt( 127 * 2 ) - 127;

//	clientCmd->flags |= (gameAdapter->Random()->RandomInt() & 1 ? UCF_IMPULSE_SEQUENCE : 0);
//	clientCmd->impulse = 11;
	/*
	bind "1" "_impulse0" fist
	bind "2" "_impulse1" pistol
	bind "3" "_impulse2" shotgun
	bind "4" "_impulse3" machinegun
	bind "5" "_impulse4" chaingun
	bind "6" "_impulse5" grenade
	bind "7" "_impulse6" plasmagun
	bind "8" "_impulse7" rocket
	bind "9" "_impulse8" bfg
	bind "0" "_impulse10" chainsaw
	bind "f" "_impulse11" flashlight
	bind "r" "_impulse13" reload
	*/
}

void idBot_D3::ProcessBotProfile( const idDict *botProfile ) {
}

void idBot_D3::UpdateBotState( void ) {
	int i;

	const idDict &info = game->GetPersistentPlayerInfo( GetClientNum() );

	health = info.GetInt( "health" );
	armor = info.GetInt( "armor" );
	weapons = info.GetInt( "weapon_bits" );

	const char *ammoTypes[ D3_AMMO_NUMTYPES ] = {
		"ammo_none",
		"ammo_shells",
		"ammo_bullets",
		"ammo_rockets",
		"ammo_cells",
		"ammo_grenades",
		"ammo_souls",
		"ammo_bfg",
		"ammo_clip",
		"ammo_belt"
	};

	for ( i = 0; i < D3_AMMO_NUMTYPES; ++i ) {
		ammo[ i ] = info.GetInt( ammoTypes[ i ] );
	}

	// obtain clip data from snapshot
	// sort of overkill, however I didn't find another method except this and hacking into entity ptr.
	idBitMsg	msg;
	byte		msgBuf[ 16384 ];
	int			startBit;

	msg.Init( msgBuf, sizeof( msgBuf ) );

	// write the game snapshot
	game->ServerWriteSnapshot( GetClientNum(), snapshotSequence, msg, clientInPVS, D3_MAX_CLIENTS );

	// starting bit of inventory info
	startBit = msg.GetNumBitsWritten() - 1512 - 296 + 184;

	if ( startBit < 0 ) {
		common->Warning( "idBotD3::UpdateSnapshot(): unable to get game snapshot\n" );
		return;
	}

	msg.SetReadCount( ( startBit >> 3 ) + 1 );
	msg.SetReadBit( startBit & 7 );

	// get clip info
	for ( i = 0; i < 16; ++i ) {
		clip[ i ] = msg.ReadBits( 7 );
	}

	snapshotSequence++;

	// TODO: powerups, current weapon
}

int idBot_D3::BotFindEnemy( void ) {
	int i;
	int enemyIndex = -1;
	double minDist = 1500.0;

	idClip *clip = gameAdapter->Clip();

	for ( i = 0; i < D3_MAX_CLIENTS; ++i ) {
		if ( i == GetClientNum() ) {
			continue; // skip myself
		}

		if ( !IsClientInPVS( i ) ) {
			continue; // skip clients not in PVS
		}

		idEntity *ent = gameAdapter->Entity( i );
		if ( !ent ) {
			continue; // this client does not exist
		}

		trace_t trace;
		clip->TracePoint( trace, GetEyePosition(), gameAdapter->EntityEyePosition( ent ), CONTENTS_SOLID, Entity() );

		if ( trace.fraction < 1.0 ) {
			continue; // traceline failed
		}

		double dist = ( GetOrigin() - gameAdapter->EntityOrigin( ent ) ).Length();
		if ( dist > minDist ) {
			continue;
		}

		// enemy found
		minDist = dist;
		enemyIndex = i;
	}
if (enemyIndex != -1) common->Printf("found enemy: %s\n", gameAdapter->GetPlayerName(enemyIndex));
	return enemyIndex;
}
