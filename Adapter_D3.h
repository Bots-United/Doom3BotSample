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

#ifndef ADAPTER_D3_H
#define ADAPTER_D3_H

class idGameAdapter_D3 : public idGameAdapter {
public:
	idGameAdapter_D3();
	virtual		~idGameAdapter_D3();

	virtual int					GetNumClients( void );
	virtual int					GetFreeClientSlot( void );
	virtual bool				IsMultiplayer( void );
	virtual bool				IsServer( void );
	virtual bool				InCinematic( void );

	virtual idDict *			ServerInfo( void );
	virtual int					GetTime( void );
	virtual idDict *			UserInfo( int clientNum );
	virtual usercmd_t *			UserCmd( int clientNum );
	virtual const char *		GetPlayerName( int clientNum );

	virtual idRandom *			Random( void );
	virtual idPVS *				PVS( void );
	virtual idClip *			Clip( void );

	virtual idEntity *			Entity( int entityNum );

	virtual const idStr &		EntityName( const idEntity *ent );
	virtual const idDict &		EntitySpawnArgs( const idEntity *ent );
	virtual const idVec3 &		EntityOrigin( const idEntity *ent );
	virtual const idVec3 &		EntityVelocity( const idEntity *ent );
	virtual const idBounds &	EntityBounds( const idEntity *ent );
	virtual const idBounds &	EntityAbsBounds( const idEntity *ent );
	virtual idVec3				EntityEyePosition( const idEntity *ent );

	//
	// D3-specific functions
	//
	bool						IsTeamplay( void );
};

#endif
