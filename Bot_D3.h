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

#ifndef BOT_D3_H
#define BOT_D3_H

#define D3_MAX_CLIENTS		32

enum D3_ammoTypes_t {
	D3_AMMO_NONE		= 0,
	D3_AMMO_SHELLS,
	D3_AMMO_BULLETS,
	D3_AMMO_ROCKETS,
	D3_AMMO_CELLS,
	D3_AMMO_GRENADES,
	D3_AMMO_SOULS,
	D3_AMMO_BFG,
	D3_AMMO_CLIP,
	D3_AMMO_BELT,

	D3_AMMO_NUMTYPES
};

enum D3_weaponTypes_t {
	D3_WEAPON_NONE		= 0,
	D3_WEAPON_FLASHLIGHT,
	D3_WEAPON_FISTS,
	D3_WEAPON_CHAINSAW,
	D3_WEAPON_PISTOL,
	D3_WEAPON_SHOTGUN,
	D3_WEAPON_SHOTGUN_DOUBLE,
	D3_WEAPON_MACHINEGUN,
	D3_WEAPON_CHAINGUN,
	D3_WEAPON_HANDGRENADE,
	D3_WEAPON_PLASMAGUN,
	D3_WEAPON_ROCKETLAUNCHER,
	D3_WEAPON_BFG,
	D3_WEAPON_SOULCUBE,
	D3_WEAPON_GRABBER,

	D3_WEAPON_NUMTYPES
};

class idBot_D3 : public idBot {
public:
	idBot_D3();
	virtual ~idBot_D3();

	virtual void	BotThink();
	virtual void	UpdateBotInput( usercmd_t *clientCmd );

protected:
	virtual void	ProcessBotProfile( const idDict *botProfile );

private:
	void			UpdateBotState( void );
	inline bool		IsClientInPVS( int clientIndex );

	int			snapshotSequence;

	byte		clientInPVS[ D3_MAX_CLIENTS / 8 ];

	int			health;
	int			armor;
	int			weapons;
	int			ammo[16];
	int			clip[16];

	//
	int			BotFindEnemy( void );

	idVec3		prevOrigin;
};

bool idBot_D3::IsClientInPVS( int clientIndex ) {
	return ( clientInPVS[ clientIndex >> 3 ] & ( 1 << ( clientIndex & 7 ) ) ) != 0;
}

#endif
