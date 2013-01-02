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

#ifndef BOT_H
#define BOT_H

class idBot {
public:
	virtual ~idBot() {}

	inline int					GetClientNum( void );
	inline const idEntity *		Entity( void );

	virtual void				BotThink() = 0;
	virtual void				UpdateBotInput( usercmd_t *clientCmd ) = 0;

	static idBot *				Factory( int clientNum, const idDict *botProfile );

protected:
	virtual void				ProcessBotProfile( const idDict *botProfile ) = 0;

	const idVec3 &				GetOrigin( void );
	idVec3						GetEyePosition( void );

private:
	int							clientNum;
};

int idBot::GetClientNum( void ) {
	return clientNum;
}

const idEntity *idBot::Entity( void ) {
	return gameAdapter->Entity( clientNum );
}

#endif
