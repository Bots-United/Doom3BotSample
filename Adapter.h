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

#ifndef ADAPTER_H
#define ADAPTER_H

class idEntity;

class idGameAdapter {
public:
	virtual ~idGameAdapter() {}

	virtual int					GetNumClients( void ) = 0;
	virtual int					GetFreeClientSlot( void ) = 0;
	virtual bool				IsMultiplayer( void ) = 0;
	virtual bool				IsServer( void ) = 0;
	virtual bool				InCinematic( void ) = 0;

	virtual idDict *			ServerInfo( void ) = 0;
	virtual int					GetTime( void ) = 0;
	virtual idDict *			UserInfo( int clientNum ) = 0;
	virtual usercmd_t *			UserCmd( int clientNum ) = 0;
	virtual const char *		GetPlayerName( int clientNum ) = 0;

	virtual idRandom *			Random( void ) = 0;
	virtual idPVS *				PVS( void ) = 0;
	virtual idClip *			Clip( void ) = 0;

	virtual idEntity *			Entity( int entityNum ) = 0;

	virtual const idStr &		EntityName( const idEntity *ent ) = 0;
	virtual const idDict &		EntitySpawnArgs( const idEntity *ent ) = 0;
	virtual const idVec3 &		EntityOrigin( const idEntity *ent ) = 0;
	virtual const idVec3 &		EntityVelocity( const idEntity *ent ) = 0;
	virtual const idBounds &	EntityBounds( const idEntity *ent ) = 0;
	virtual const idBounds &	EntityAbsBounds( const idEntity *ent ) = 0;
	virtual idVec3				EntityEyePosition( const idEntity *ent ) = 0;

	static idGameAdapter *		Factory( void );
};

extern idGameAdapter *gameAdapter;

void InitGameAdapter( void );
void ShutdownGameAdapter( void );

#endif
