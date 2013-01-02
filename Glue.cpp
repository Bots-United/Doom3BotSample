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
#include "../game/Game_local.h"

/*
============
idGameLocal::Printf
============
*/
void idGameLocal::Printf( const char *fmt, ... ) const {
	va_list		argptr;
	char		text[MAX_STRING_CHARS];

	va_start( argptr, fmt );
	idStr::vsnPrintf( text, sizeof( text ), fmt, argptr );
	va_end( argptr );

	common->Printf( "%s", text );
}

/*
============
idGameLocal::DPrintf
============
*/
void idGameLocal::DPrintf( const char *fmt, ... ) const {
	va_list		argptr;
	char		text[MAX_STRING_CHARS];

	va_start( argptr, fmt );
	idStr::vsnPrintf( text, sizeof( text ), fmt, argptr );
	va_end( argptr );

	common->DPrintf( "%s", text );
}

/*
============
idGameLocal::Warning
============
*/
void idGameLocal::Warning( const char *fmt, ... ) const {
	va_list		argptr;
	char		text[MAX_STRING_CHARS];

	va_start( argptr, fmt );
	idStr::vsnPrintf( text, sizeof( text ), fmt, argptr );
	va_end( argptr );

	common->Warning( "%s", text );
}

/*
============
idGameLocal::DWarning
============
*/
void idGameLocal::DWarning( const char *fmt, ... ) const {
	va_list		argptr;
	char		text[MAX_STRING_CHARS];

	va_start( argptr, fmt );
	idStr::vsnPrintf( text, sizeof( text ), fmt, argptr );
	va_end( argptr );

	common->DWarning( "%s", text );
}

/*
============
idGameLocal::Error
============
*/
void idGameLocal::Error( const char *fmt, ... ) const {
	va_list		argptr;
	char		text[MAX_STRING_CHARS];

	va_start( argptr, fmt );
	idStr::vsnPrintf( text, sizeof( text ), fmt, argptr );
	va_end( argptr );

	common->Error( "%s", text );
}

void idSaveGame::WriteString( const char * ) {
}

void idSaveGame::WriteMaterial( const idMaterial * ) {
}

void idSaveGame::WriteBounds( const idBounds &bounds ) {
}

void idSaveGame::WriteMat3( const idMat3 &mat ) {
}

void idSaveGame::WriteVec3( const idVec3 &vec ) {
}

void idSaveGame::WriteInt( const int value ) {
}

void idSaveGame::WriteObject( const idClass *obj ) {
}

void idSaveGame::WriteBool( const bool value ) {
}

void idSaveGame::WriteFloat( const float value ) {
}

void idSaveGame::WriteTraceModel( const idTraceModel &trace ) {
}

void idRestoreGame::ReadMat3( idMat3 &mat ) {
}

void idRestoreGame::ReadVec3( idVec3 &vec ) {
}

void idRestoreGame::ReadFloat( float &value ) {
}

void idRestoreGame::ReadTraceModel( idTraceModel &trace ) {
}

void idRestoreGame::ReadInt( int &value ) {
}

void idRestoreGame::ReadString( idStr &string ) {
}

void idRestoreGame::ReadMaterial( const idMaterial *&material ) {
}

void idRestoreGame::ReadBounds( idBounds &bounds ) {
}

void idRestoreGame::ReadObject( idClass *&obj ) {
}

void idRestoreGame::ReadBool( bool &value ) {
}

/*
================
idEntity::GetPhysics
================
*/
idPhysics *idEntity::GetPhysics() const {
	return physics;
}

/*
================
idEntity::GetName
================
*/
const char *idEntity::GetName() const {
	return name.c_str();
}

#define gameLocal (*(static_cast<idGameLocal *>(game)))

#include "../game/Pvs.cpp"
#include "../game/physics/Clip.cpp"
