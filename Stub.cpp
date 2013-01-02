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

#include "../idlib/precompiled.h"
#include "../game/Game_local.h"

void idNetworkSystem::ServerSendReliableMessage( int clientNum, const idBitMsg &msg ) {
	common->FatalError( "idNetworkSystem::ServerSendReliableMessage(): stub called" );
}

void idNetworkSystem::ServerSendReliableMessageExcluding( int clientNum, const idBitMsg &msg ) {
	common->FatalError( "idNetworkSystem::ServerSendReliableMessageExcluding(): stub called" );
}

int idNetworkSystem::ServerGetClientPing( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientPing(): stub called" );
	return -1;
}

int idNetworkSystem::ServerGetClientPrediction( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientPrediction(): stub called" );
	return -1;
}

int idNetworkSystem::ServerGetClientTimeSinceLastPacket( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientTimeSinceLastPacket(): stub called" );
	return -1;
}

int idNetworkSystem::ServerGetClientTimeSinceLastInput( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientTimeSinceLastInput(): stub called" );
	return -1;
}

int idNetworkSystem::ServerGetClientOutgoingRate( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientOutgoingRate(): stub called" );
	return -1;
}

int idNetworkSystem::ServerGetClientIncomingRate( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientIncomingRate(): stub called" );
	return -1;
}

float idNetworkSystem::ServerGetClientIncomingPacketLoss( int clientNum ) {
	common->FatalError( "idNetworkSystem::ServerGetClientIncomingPacketLoss(): stub called" );
	return -1;
}

void idNetworkSystem::ClientSendReliableMessage( const idBitMsg &msg ) {
	common->FatalError( "idNetworkSystem::ClientSendReliableMessage(): stub called" );
}

int idNetworkSystem::ClientGetPrediction( void ) {
	common->FatalError( "idNetworkSystem::ClientGetPrediction(): stub called" );
	return -1;
}

int idNetworkSystem::ClientGetTimeSinceLastPacket( void ) {
	common->FatalError( "idNetworkSystem::ClientGetTimeSinceLastPacket(): stub called" );
	return -1;
}

int idNetworkSystem::ClientGetOutgoingRate( void ) {
	common->FatalError( "idNetworkSystem::ClientGetOutgoingRate(): stub called" );
	return -1;
}

int idNetworkSystem::ClientGetIncomingRate( void ) {
	common->FatalError( "idNetworkSystem::ClientGetIncomingRate(): stub called" );
	return -1;
}

float idNetworkSystem::ClientGetIncomingPacketLoss( void ) {
	common->FatalError( "idNetworkSystem::ClientGetIncomingPacketLoss(): stub called" );
	return -1;
}

idPhysics::~idPhysics() {
	common->Error( "idPhysics::~idPhysics(): stub called" );
}

idTypeInfo *idPhysics::GetType( void ) const {
	common->Error( "idPhysics::~GetType(): stub called" );
	return NULL;
}

void idPhysics::SetClipBox( const idBounds &bounds, float density ) {
	common->Error( "idPhysics::SetClipBox(): stub called" );
}

idTypeInfo *idPhysics_Actor::GetType( void ) const {
	common->Error( "idPhysics_Actor::GetType(): stub called" );
	return NULL;
}

void idPhysics_Actor::SetClipModel( idClipModel *model, float density, int id, bool freeOld ) {
	common->Error( "idPhysics_Actor::SetClipModel(): stub called" );
}

idPhysics_Static::~idPhysics_Static() {
	common->Error( "idPhysics_Static::~idPhysics_Static(): stub called" );
}

idTypeInfo *idPhysics_Static::GetType() const {
	common->Error( "idPhysics_Static::GetType(): stub called" );
	return NULL;
}

void idPhysics_Static::SetSelf( idEntity *e ) {
	common->Error( "idPhysics_Static::SetSelf(): stub called" );
}

void idPhysics_Static::SetClipModel( idClipModel *model, float density, int id, bool freeOld ) {
	common->Error( "idPhysics_Static::SetClipModel(): stub called" );
}

idClipModel *idPhysics_Static::GetClipModel( int id ) const {
	common->Error( "idPhysics_Static::GetClipModel(): stub called" );
	return NULL;
}

int idPhysics_Static::GetNumClipModels() const {
	common->Error( "idPhysics_Static::GetNumClipModels(): stub called" );
	return -1;
}

void idPhysics_Static::SetMass( float mass, int id ) {
	common->Error( "idPhysics_Static::SetMass(): stub called" );
}

float idPhysics_Static::GetMass( int id ) const {
	common->Error( "idPhysics_Static::GetMass(): stub called" );
	return 0.0f;
}

void idPhysics_Static::SetContents( int contents, int id ) {
	common->Error( "idPhysics_Static::SetContents(): stub called" );
}

int idPhysics_Static::GetContents( int id ) const {
	common->Error( "idPhysics_Static::GetContents(): stub called" );
	return -1;
}

void idPhysics_Static::SetClipMask( int mask, int id ) {
	common->Error( "idPhysics_Static::SetClipMask(): stub called" );
}

int idPhysics_Static::GetClipMask( int id ) const {
	common->Error( "idPhysics_Static::GetClipMask(): stub called" );
	return -1;
}

const idBounds &idPhysics_Static::GetBounds( int id ) const {
	common->Error( "idPhysics_Static::GetBounds(): stub called" );
	return *( const idBounds * )NULL;
}

const idBounds &idPhysics_Static::GetAbsBounds( int id ) const {
	common->Error( "idPhysics_Static::GetAbsBounds(): stub called" );
	return *( const idBounds * )NULL;
}

bool idPhysics_Static::Evaluate( int timeStepMSec, int endTimeMSec ) {
	common->Error( "idPhysics_Static::Evaluate(): stub called" );
	return false;
}

void idPhysics_Static::UpdateTime( int endTimeMSec ) {
	common->Error( "idPhysics_Static::UpdateTime(): stub called" );
}

int idPhysics_Static::GetTime() const {
	common->Error( "idPhysics_Static::GetTime(): stub called" );
	return -1;
}

void idPhysics_Static::GetImpactInfo( const int id, const idVec3 &point, impactInfo_t *info ) const {
	common->Error( "idPhysics_Static::GetImpactInfo(): stub called" );
}

void idPhysics_Static::ApplyImpulse( const int id, const idVec3 &point, const idVec3 &impulse ) {
	common->Error( "idPhysics_Static::ApplyImpulse(): stub called" );
}

void idPhysics_Static::AddForce( const int id, const idVec3 &point, const idVec3 &force ) {
	common->Error( "idPhysics_Static::AddForce(): stub called" );
}

void idPhysics_Static::Activate( void ) {
	common->Error( "idPhysics_Static::Activate(): stub called" );
}

void idPhysics_Static::PutToRest( void ) {
	common->Error( "idPhysics_Static::PutToRest(): stub called" );
}

bool idPhysics_Static::IsAtRest( void ) const {
	common->Error( "idPhysics_Static::IsAtRest(): stub called" );
	return false;
}

int idPhysics_Static::GetRestStartTime( void ) const {
	common->Error( "idPhysics_Static::GetRestStartTime(): stub called" );
	return -1;
}

bool idPhysics_Static::IsPushable( void ) const {
	common->Error( "idPhysics_Static::IsPushable(): stub called" );
	return false;
}

void idPhysics_Static::SaveState( void ) {
	common->Error( "idPhysics_Static::SaveState(): stub called" );
}

void idPhysics_Static::RestoreState( void ) {
	common->Error( "idPhysics_Static::RestoreState(): stub called" );
}

void idPhysics_Static::SetOrigin( const idVec3 &newOrigin, int id ) {
	common->Error( "idPhysics_Static::SetOrigin(): stub called" );
}

void idPhysics_Static::SetAxis( const idMat3 &newAxis, int id ) {
	common->Error( "idPhysics_Static::SetAxis(): stub called" );
}

void idPhysics_Static::Translate( const idVec3 &translation, int id ) {
	common->Error( "idPhysics_Static::Translate(): stub called" );
}

void idPhysics_Static::Rotate( const idRotation &rotation, int id ) {
	common->Error( "idPhysics_Static::Rotate(): stub called" );
}

const idVec3 &idPhysics_Static::GetOrigin( int id ) const {
	common->Error( "idPhysics_Static::GetOrigin(): stub called" );
	return *( const idVec3 *)NULL;
}

const idMat3 &idPhysics_Static::GetAxis( int id ) const {
	common->Error( "idPhysics_Static::GetAxis(): stub called" );
	return *( const idMat3 *)NULL;
}

void idPhysics_Static::SetLinearVelocity( const idVec3 &newLinearVelocity, int id ) {
	common->Error( "idPhysics_Static::SetLinearVelocity(): stub called" );
}

void idPhysics_Static::SetAngularVelocity( const idVec3 &newAngularVelocity, int id ) {
	common->Error( "idPhysics_Static::SetAngularVelocity(): stub called" );
}

void idPhysics_Static::SetGravity( const idVec3 &newGravity ) {
	common->Error( "idPhysics_Static::SetGravity(): stub called" );
}

const idVec3 &idPhysics_Static::GetGravity( void ) const {
	common->Error( "idPhysics_Static::GetGravity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 &idPhysics_Static::GetGravityNormal( void ) const {
	common->Error( "idPhysics_Static::GetGravityNormal(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 &idPhysics_Static::GetLinearVelocity( int id ) const {
	common->Error( "idPhysics_Static::GetLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 &idPhysics_Static::GetAngularVelocity( int id ) const {
	common->Error( "idPhysics_Static::GetAngularVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

void idPhysics_Static::ClipTranslation( trace_t &results, const idVec3 &translation, const idClipModel *model ) const {
	common->Error( "idPhysics_Static::ClipTranslation(): stub called" );
}

void idPhysics_Static::ClipRotation( trace_t &results, const idRotation &rotation, const idClipModel *model ) const {
	common->Error( "idPhysics_Static::ClipRotation(): stub called" );
}

int idPhysics_Static::ClipContents( const idClipModel *model ) const {
	common->Error( "idPhysics_Static::ClipContents(): stub called" );
	return -1;
}

void idPhysics_Static::DisableClip( void ) {
	common->Error( "idPhysics_Static::DisableClip(): stub called" );
}

void idPhysics_Static::EnableClip( void ) {
	common->Error( "idPhysics_Static::EnableClip(): stub called" );
}

void idPhysics_Static::UnlinkClip( void ) {
	common->Error( "idPhysics_Static::UnlinkClip(): stub called" );
}

void idPhysics_Static::LinkClip( void ) {
	common->Error( "idPhysics_Static::LinkClip(): stub called" );
}

bool idPhysics_Static::EvaluateContacts( void ) {
	common->Error( "idPhysics_Static::EvaluateContacts(): stub called" );
	return false;
}

int idPhysics_Static::GetNumContacts( void ) const {
	common->Error( "idPhysics_Static::GetNumContacts(): stub called" );
	return -1;
}

const contactInfo_t & idPhysics_Static::GetContact( int num ) const {
	common->Error( "idPhysics_Static::GetContact(): stub called" );
	return *( contactInfo_t *)NULL;
}

void idPhysics_Static::ClearContacts( void ) {
	common->Error( "idPhysics_Static::ClearContacts(): stub called" );
}

void idPhysics_Static::AddContactEntity( idEntity *e ) {
	common->Error( "idPhysics_Static::AddContactEntity(): stub called" );
}

void idPhysics_Static::RemoveContactEntity( idEntity *e ) {
	common->Error( "idPhysics_Static::RemoveContactEntity(): stub called" );
}

bool idPhysics_Static::HasGroundContacts( void ) const {
	common->Error( "idPhysics_Static::HasGroundContacts(): stub called" );
	return false;
}

bool idPhysics_Static::IsGroundEntity( int ) const {
	common->Error( "idPhysics_Static::IsGroundEntity(): stub called" );
	return false;
}

bool idPhysics_Static::IsGroundClipModel( int, int ) const {
	common->Error( "idPhysics_Static::IsGroundClipModel(): stub called" );
	return false;
}

void idPhysics_Static::SetMaster( idEntity *, bool ) {
	common->Error( "idPhysics_Static::SetMaster(): stub called" );
}

void idPhysics_Static::SetPushed( int deltaTime ) {
	common->Error( "idPhysics_Static::SetPushed(): stub called" );
}

const idVec3 & idPhysics_Static::GetPushedLinearVelocity( int ) const {
	common->Error( "idPhysics_Static::GetPushedLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 & idPhysics_Static::GetPushedAngularVelocity( int ) const {
	common->Error( "idPhysics_Static::GetPushedAngularVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const trace_t * idPhysics_Static::GetBlockingInfo( void ) const {
	common->Error( "idPhysics_Static::GetBlockingInfo(): stub called" );
	return NULL;
}

idEntity * idPhysics_Static::GetBlockingEntity(void)const {
	common->Error( "idPhysics_Static::GetBlockingEntity(): stub called" );
	return NULL;
}

int idPhysics_Static::GetLinearEndTime( void ) const {
	common->Error( "idPhysics_Static::GetLinearEndTime(): stub called" );
	return -1;
}

int idPhysics_Static::GetAngularEndTime( void ) const {
	common->Error( "idPhysics_Static::GetAngularEndTime(): stub called" );
	return -1;
}

void idPhysics_Static::WriteToSnapshot( idBitMsgDelta & ) const {
	common->Error( "idPhysics_Static::WriteToSnapshot(): stub called" );
}

void idPhysics_Static::ReadFromSnapshot( const idBitMsgDelta & ) {
	common->Error( "idPhysics_Static::ReadFromSnapshot(): stub called" );
}

idPhysics_Base::~idPhysics_Base() {
	common->Error( "idPhysics_Base::~idPhysics_Base(): stub called" );
}

idTypeInfo *idPhysics_Base::GetType() const {
	common->Error( "idPhysics_Base::GetType(): stub called" );
	return NULL;
}

void idPhysics_Base::SetSelf( idEntity *e ) {
	common->Error( "idPhysics_Base::SetSelf(): stub called" );
}

void idPhysics_Base::SetClipModel( idClipModel *model, float density, int id, bool freeOld ) {
	common->Error( "idPhysics_Base::SetClipModel(): stub called" );
}

idClipModel *idPhysics_Base::GetClipModel( int id ) const {
	common->Error( "idPhysics_Base::GetClipModel(): stub called" );
	return NULL;
}

int idPhysics_Base::GetNumClipModels() const {
	common->Error( "idPhysics_Base::GetNumClipModels(): stub called" );
	return -1;
}

void idPhysics_Base::SetMass( float mass, int id ) {
	common->Error( "idPhysics_Base::SetMass(): stub called" );
}

float idPhysics_Base::GetMass( int id ) const {
	common->Error( "idPhysics_Base::GetMass(): stub called" );
	return 0.0f;
}

void idPhysics_Base::SetContents( int contents, int id ) {
	common->Error( "idPhysics_Base::SetContents(): stub called" );
}

int idPhysics_Base::GetContents( int id ) const {
	common->Error( "idPhysics_Base::GetContents(): stub called" );
	return -1;
}

void idPhysics_Base::SetClipMask( int mask, int id ) {
	common->Error( "idPhysics_Base::SetClipMask(): stub called" );
}

int idPhysics_Base::GetClipMask( int id ) const {
	common->Error( "idPhysics_Base::GetClipMask(): stub called" );
	return -1;
}

const idBounds &idPhysics_Base::GetBounds( int id ) const {
	common->Error( "idPhysics_Base::GetBounds(): stub called" );
	return *( const idBounds * )NULL;
}

const idBounds &idPhysics_Base::GetAbsBounds( int id ) const {
	common->Error( "idPhysics_Base::GetAbsBounds(): stub called" );
	return *( const idBounds * )NULL;
}

bool idPhysics_Base::Evaluate( int timeStepMSec, int endTimeMSec ) {
	common->Error( "idPhysics_Base::Evaluate(): stub called" );
	return false;
}

void idPhysics_Base::UpdateTime( int endTimeMSec ) {
	common->Error( "idPhysics_Base::UpdateTime(): stub called" );
}

int idPhysics_Base::GetTime() const {
	common->Error( "idPhysics_Base::GetTime(): stub called" );
	return -1;
}

void idPhysics_Base::GetImpactInfo( const int id, const idVec3 &point, impactInfo_t *info ) const {
	common->Error( "idPhysics_Base::GetImpactInfo(): stub called" );
}

void idPhysics_Base::ApplyImpulse( const int id, const idVec3 &point, const idVec3 &impulse ) {
	common->Error( "idPhysics_Base::ApplyImpulse(): stub called" );
}

void idPhysics_Base::AddForce( const int id, const idVec3 &point, const idVec3 &force ) {
	common->Error( "idPhysics_Base::AddForce(): stub called" );
}

void idPhysics_Base::Activate( void ) {
	common->Error( "idPhysics_Base::Activate(): stub called" );
}

void idPhysics_Base::PutToRest( void ) {
	common->Error( "idPhysics_Base::PutToRest(): stub called" );
}

bool idPhysics_Base::IsAtRest( void ) const {
	common->Error( "idPhysics_Base::IsAtRest(): stub called" );
	return false;
}

int idPhysics_Base::GetRestStartTime( void ) const {
	common->Error( "idPhysics_Base::GetRestStartTime(): stub called" );
	return -1;
}

bool idPhysics_Base::IsPushable( void ) const {
	common->Error( "idPhysics_Base::IsPushable(): stub called" );
	return false;
}

void idPhysics_Base::SaveState( void ) {
	common->Error( "idPhysics_Base::SaveState(): stub called" );
}

void idPhysics_Base::RestoreState( void ) {
	common->Error( "idPhysics_Base::RestoreState(): stub called" );
}

void idPhysics_Base::SetOrigin( const idVec3 &newOrigin, int id ) {
	common->Error( "idPhysics_Base::SetOrigin(): stub called" );
}

void idPhysics_Base::SetAxis( const idMat3 &newAxis, int id ) {
	common->Error( "idPhysics_Base::SetAxis(): stub called" );
}

void idPhysics_Base::Translate( const idVec3 &translation, int id ) {
	common->Error( "idPhysics_Base::Translate(): stub called" );
}

void idPhysics_Base::Rotate( const idRotation &rotation, int id ) {
	common->Error( "idPhysics_Base::Rotate(): stub called" );
}

const idVec3 &idPhysics_Base::GetOrigin( int id ) const {
	common->Error( "idPhysics_Base::GetOrigin(): stub called" );
	return *( const idVec3 *)NULL;
}

const idMat3 &idPhysics_Base::GetAxis( int id ) const {
	common->Error( "idPhysics_Base::GetAxis(): stub called" );
	return *( const idMat3 *)NULL;
}

void idPhysics_Base::SetLinearVelocity( const idVec3 &newLinearVelocity, int id ) {
	common->Error( "idPhysics_Base::SetLinearVelocity(): stub called" );
}

void idPhysics_Base::SetAngularVelocity( const idVec3 &newAngularVelocity, int id ) {
	common->Error( "idPhysics_Base::SetAngularVelocity(): stub called" );
}

const idVec3 &idPhysics_Base::GetLinearVelocity( int id ) const {
	common->Error( "idPhysics_Base::GetLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 &idPhysics_Base::GetAngularVelocity( int id ) const {
	common->Error( "idPhysics_Base::GetAngularVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

void idPhysics_Base::SetGravity( const idVec3 &newGravity ) {
	common->Error( "idPhysics_Base::SetGravity(): stub called" );
}

const idVec3 &idPhysics_Base::GetGravity( void ) const {
	common->Error( "idPhysics_Base::GetGravity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 &idPhysics_Base::GetGravityNormal( void ) const {
	common->Error( "idPhysics_Base::GetGravityNormal(): stub called" );
	return *( const idVec3 * )NULL;
}

void idPhysics_Base::ClipTranslation( trace_t &results, const idVec3 &translation, const idClipModel *model ) const {
	common->Error( "idPhysics_Base::ClipTranslation(): stub called" );
}

void idPhysics_Base::ClipRotation( trace_t &results, const idRotation &rotation, const idClipModel *model ) const {
	common->Error( "idPhysics_Base::ClipRotation(): stub called" );
}

int idPhysics_Base::ClipContents( const idClipModel *model ) const {
	common->Error( "idPhysics_Base::ClipContents(): stub called" );
	return -1;
}

void idPhysics_Base::DisableClip( void ) {
	common->Error( "idPhysics_Base::DisableClip(): stub called" );
}

void idPhysics_Base::EnableClip( void ) {
	common->Error( "idPhysics_Base::EnableClip(): stub called" );
}

void idPhysics_Base::UnlinkClip( void ) {
	common->Error( "idPhysics_Base::UnlinkClip(): stub called" );
}

void idPhysics_Base::LinkClip( void ) {
	common->Error( "idPhysics_Base::LinkClip(): stub called" );
}

bool idPhysics_Base::EvaluateContacts( void ) {
	common->Error( "idPhysics_Base::EvaluateContacts(): stub called" );
	return false;
}

int idPhysics_Base::GetNumContacts( void ) const {
	common->Error( "idPhysics_Base::GetNumContacts(): stub called" );
	return -1;
}

const contactInfo_t & idPhysics_Base::GetContact( int num ) const {
	common->Error( "idPhysics_Base::GetContact(): stub called" );
	return *( contactInfo_t *)NULL;
}

void idPhysics_Base::ClearContacts( void ) {
	common->Error( "idPhysics_Base::ClearContacts(): stub called" );
}

void idPhysics_Base::AddContactEntity( idEntity *e ) {
	common->Error( "idPhysics_Base::AddContactEntity(): stub called" );
}

void idPhysics_Base::RemoveContactEntity( idEntity *e ) {
	common->Error( "idPhysics_Base::RemoveContactEntity(): stub called" );
}

bool idPhysics_Base::HasGroundContacts( void ) const {
	common->Error( "idPhysics_Base::HasGroundContacts(): stub called" );
	return false;
}

bool idPhysics_Base::IsGroundEntity( int ) const {
	common->Error( "idPhysics_Base::IsGroundEntity(): stub called" );
	return false;
}

bool idPhysics_Base::IsGroundClipModel( int, int ) const {
	common->Error( "idPhysics_Base::IsGroundClipModel(): stub called" );
	return false;
}

void idPhysics_Base::SetMaster( idEntity *, bool ) {
	common->Error( "idPhysics_Base::SetMaster(): stub called" );
}

void idPhysics_Base::SetPushed( int deltaTime ) {
	common->Error( "idPhysics_Base::SetPushed(): stub called" );
}

const idVec3 & idPhysics_Base::GetPushedLinearVelocity( int ) const {
	common->Error( "idPhysics_Base::GetPushedLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const idVec3 & idPhysics_Base::GetPushedAngularVelocity( int ) const {
	common->Error( "idPhysics_Base::GetPushedAngularVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

const trace_t * idPhysics_Base::GetBlockingInfo( void ) const {
	common->Error( "idPhysics_Base::GetBlockingInfo(): stub called" );
	return NULL;
}

idEntity * idPhysics_Base::GetBlockingEntity(void)const {
	common->Error( "idPhysics_Base::GetBlockingEntity(): stub called" );
	return NULL;
}

int idPhysics_Base::GetLinearEndTime( void ) const {
	common->Error( "idPhysics_Base::GetLinearEndTime(): stub called" );
	return -1;
}

int idPhysics_Base::GetAngularEndTime( void ) const {
	common->Error( "idPhysics_Base::GetAngularEndTime(): stub called" );
	return -1;
}

void idPhysics_Base::WriteToSnapshot( idBitMsgDelta & ) const {
	common->Error( "idPhysics_Base::WriteToSnapshot(): stub called" );
}

void idPhysics_Base::ReadFromSnapshot( const idBitMsgDelta & ) {
	common->Error( "idPhysics_Base::ReadFromSnapshot(): stub called" );
}

idPhysics_Actor::~idPhysics_Actor() {
	common->Error( "idPhysics_Actor::~idPhysics_Actor(): stub called" );
}

idClipModel *idPhysics_Actor::GetClipModel( int id ) const {
	common->Error( "idPhysics_Actor::GetClipModel(): stub called" );
	return NULL;
}

int idPhysics_Actor::GetNumClipModels() const {
	common->Error( "idPhysics_Actor::GetNumClipModels(): stub called" );
	return -1;
}

void idPhysics_Actor::SetMass( float mass, int id ) {
	common->Error( "idPhysics_Actor::SetMass(): stub called" );
}

float idPhysics_Actor::GetMass( int id ) const {
	common->Error( "idPhysics_Actor::GetMass(): stub called" );
	return 0.0f;
}

void idPhysics_Actor::SetContents( int contents, int id ) {
	common->Error( "idPhysics_Actor::SetContents(): stub called" );
}

int idPhysics_Actor::GetContents( int id ) const {
	common->Error( "idPhysics_Actor::GetContents(): stub called" );
	return -1;
}

const idBounds &idPhysics_Actor::GetBounds( int id ) const {
	common->Error( "idPhysics_Actor::GetBounds(): stub called" );
	return *( const idBounds * )NULL;
}

const idBounds &idPhysics_Actor::GetAbsBounds( int id ) const {
	common->Error( "idPhysics_Actor::GetAbsBounds(): stub called" );
	return *( const idBounds * )NULL;
}

bool idPhysics_Actor::IsPushable( void ) const {
	common->Error( "idPhysics_Actor::IsPushable(): stub called" );
	return false;
}

const idVec3 &idPhysics_Actor::GetOrigin( int id ) const {
	common->Error( "idPhysics_Actor::GetOrigin(): stub called" );
	return *( const idVec3 *)NULL;
}

const idMat3 &idPhysics_Actor::GetAxis( int id ) const {
	common->Error( "idPhysics_Actor::GetAxis(): stub called" );
	return *( const idMat3 *)NULL;
}

void idPhysics_Actor::SetGravity( const idVec3 &newGravity ) {
	common->Error( "idPhysics_Actor::SetGravity(): stub called" );
}

void idPhysics_Actor::ClipTranslation( trace_t &results, const idVec3 &translation, const idClipModel *model ) const {
	common->Error( "idPhysics_Actor::ClipTranslation(): stub called" );
}

void idPhysics_Actor::ClipRotation( trace_t &results, const idRotation &rotation, const idClipModel *model ) const {
	common->Error( "idPhysics_Actor::ClipRotation(): stub called" );
}

int idPhysics_Actor::ClipContents( const idClipModel *model ) const {
	common->Error( "idPhysics_Actor::ClipContents(): stub called" );
	return -1;
}

void idPhysics_Actor::DisableClip( void ) {
	common->Error( "idPhysics_Actor::DisableClip(): stub called" );
}

void idPhysics_Actor::EnableClip( void ) {
	common->Error( "idPhysics_Actor::EnableClip(): stub called" );
}

void idPhysics_Actor::UnlinkClip( void ) {
	common->Error( "idPhysics_Actor::UnlinkClip(): stub called" );
}

void idPhysics_Actor::LinkClip( void ) {
	common->Error( "idPhysics_Actor::LinkClip(): stub called" );
}

bool idPhysics_Actor::EvaluateContacts( void ) {
	common->Error( "idPhysics_Actor::EvaluateContacts(): stub called" );
	return false;
}

idTypeInfo *idPhysics_Player::GetType() const {
	common->Error( "idPhysics_Player::GetType(): stub called" );
	return NULL;
}

bool idPhysics_Player::Evaluate( int timeStepMSec, int endTimeMSec ) {
	common->Error( "idPhysics_Player::Evaluate(): stub called" );
	return false;
}

void idPhysics_Player::UpdateTime( int endTimeMSec ) {
	common->Error( "idPhysics_Player::UpdateTime(): stub called" );
}

int idPhysics_Player::GetTime() const {
	common->Error( "idPhysics_Player::GetTime(): stub called" );
	return -1;
}

void idPhysics_Player::GetImpactInfo( const int id, const idVec3 &point, impactInfo_t *info ) const {
	common->Error( "idPhysics_Player::GetImpactInfo(): stub called" );
}

void idPhysics_Player::ApplyImpulse( const int id, const idVec3 &point, const idVec3 &impulse ) {
	common->Error( "idPhysics_Player::ApplyImpulse(): stub called" );
}

bool idPhysics_Player::IsAtRest( void ) const {
	common->Error( "idPhysics_Player::IsAtRest(): stub called" );
	return false;
}

int idPhysics_Player::GetRestStartTime( void ) const {
	common->Error( "idPhysics_Player::GetRestStartTime(): stub called" );
	return -1;
}

void idPhysics_Player::SaveState( void ) {
	common->Error( "idPhysics_Player::SaveState(): stub called" );
}

void idPhysics_Player::RestoreState( void ) {
	common->Error( "idPhysics_Player::RestoreState(): stub called" );
}

void idPhysics_Player::SetOrigin( const idVec3 &newOrigin, int id ) {
	common->Error( "idPhysics_Player::SetOrigin(): stub called" );
}

void idPhysics_Player::SetAxis( const idMat3 &newAxis, int id ) {
	common->Error( "idPhysics_Player::SetAxis(): stub called" );
}

void idPhysics_Player::Translate( const idVec3 &translation, int id ) {
	common->Error( "idPhysics_Player::Translate(): stub called" );
}

void idPhysics_Player::Rotate( const idRotation &rotation, int id ) {
	common->Error( "idPhysics_Player::Rotate(): stub called" );
}

void idPhysics_Player::SetLinearVelocity( const idVec3 &newLinearVelocity, int id ) {
	common->Error( "idPhysics_Player::SetLinearVelocity(): stub called" );
}

const idVec3 &idPhysics_Player::GetLinearVelocity( int id ) const {
	common->Error( "idPhysics_Player::GetLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

void idPhysics_Player::SetMaster( idEntity *, bool ) {
	common->Error( "idPhysics_Player::SetMaster(): stub called" );
}

void idPhysics_Player::SetPushed( int deltaTime ) {
	common->Error( "idPhysics_Player::SetPushed(): stub called" );
}

const idVec3 & idPhysics_Player::GetPushedLinearVelocity( int ) const {
	common->Error( "idPhysics_Player::GetPushedLinearVelocity(): stub called" );
	return *( const idVec3 * )NULL;
}

void idPhysics_Player::WriteToSnapshot( idBitMsgDelta & ) const {
	common->Error( "idPhysics_Player::WriteToSnapshot(): stub called" );
}

void idPhysics_Player::ReadFromSnapshot( const idBitMsgDelta & ) {
	common->Error( "idPhysics_Player::ReadFromSnapshot(): stub called" );
}

idClass::~idClass() {
	common->Error( "idClass::~idClass(): stub called" );
}

idTypeInfo *idClass::GetType( void ) const {
	common->Error( "idClass::GetType(): stub called" );
	return NULL;
}

void idClass::operator delete( void * ) {
	common->Error( "idClass::operator delete: stub called" );
}

idScriptObject::~idScriptObject() {
	common->Error( "idScriptObject::~idScriptObject(): stub called" );
}

idEntity::~idEntity() {
	common->Error( "idEntity::~idEntity(): stub called" );
}

idTypeInfo *idEntity::GetType( void ) const {
	common->Error( "idEntity::GetType(): stub called" );
	return NULL;
}

void idEntity::UpdateChangeableSpawnArgs( const idDict *source ) {
	common->Error( "idEntity::UpdateChangeableSpawnArgs(): stub called" );
}

renderView_t *idEntity::GetRenderView() {
	common->Error( "idEntity::GetRenderView(): stub called" );
	return NULL;
}

void idEntity::Think( void ) {
	common->Error( "idEntity::Think(): stub called" );
}

void idEntity::DormantBegin( void ) {
	common->Error( "idEntity::DormantBegin(): stub called" );
}

void idEntity::DormantEnd( void ) {
	common->Error( "idEntity::DormantEnd(): stub called" );
}

void idEntity::Present( void ) {
	common->Error( "idEntity::Present(): stub called" );
}

renderEntity_t * idEntity::GetRenderEntity( void ) {
	common->Error( "idEntity::GetRenderEntity(): stub called" );
	return NULL;
}

int idEntity::GetModelDefHandle( void ) {
	common->Error( "idEntity::GetModelDefHandle(): stub called" );
	return -1;
}

void idEntity::SetModel( const char *modelname ) {
	common->Error( "idEntity::SetModel(): stub called" );
}

void idEntity::SetColor( float red, float green, float blue ) {
	common->Error( "idEntity::SetColor(): stub called" );
}

void idEntity::SetColor( const idVec3 &color ) {
	common->Error( "idEntity::SetColor(): stub called" );
}

void idEntity::GetColor( idVec3 &out ) const {
	common->Error( "idEntity::GetColor(): stub called" );
}

void idEntity::SetColor( const idVec4 &color ) {
	common->Error( "idEntity::SetColor(): stub called" );
}

void idEntity::GetColor( idVec4 &out ) const {
	common->Error( "idEntity::GetColor(): stub called" );
}

void idEntity::FreeModelDef( void ) {
	common->Error( "idEntity::FreeModelDef(): stub called" );
}

void idEntity::FreeLightDef( void ) {
	common->Error( "idEntity::FreeLightDef(): stub called" );
}

void idEntity::Hide( void ) {
	common->Error( "idEntity::Hide(): stub called" );
}

void idEntity::Show( void ) {
	common->Error( "idEntity::Show(): stub called" );
}

void idEntity::ProjectOverlay( const idVec3 &origin, const idVec3 &dir, float size, const char *material ) {
	common->Error( "idEntity::ProjectOverlay(): stub called" );
}

bool idEntity::UpdateAnimationControllers( void ) {
	common->Error( "idEntity::UpdateAnimationControllers(): stub called" );
	return false;
}

idAnimator * idEntity::GetAnimator( void ) {
	common->Error( "idEntity::GetAnimator(): stub called" );
	return NULL;
}

bool idEntity::CanPlayChatterSounds( void ) const {
	common->Error( "idEntity::CanPlayChatterSounds(): stub called" );
	return false;
}

void idEntity::PreBind( void ) {
	common->Error( "idEntity::PreBind(): stub called" );
}

void idEntity::PostBind( void ) {
	common->Error( "idEntity::PostBind(): stub called" );
}

void idEntity::PreUnbind( void ) {
	common->Error( "idEntity::PreUnbind(): stub called" );
}

void idEntity::PostUnbind( void ) {
	common->Error( "idEntity::PostUnbind(): stub called" );
}

bool idEntity::GetPhysicsToVisualTransform( idVec3 &origin, idMat3 &axis ) {
	common->Error( "idEntity::GetPhysicsToVisualTransform(): stub called" );
	return false;
}

bool idEntity::GetPhysicsToSoundTransform( idVec3 &origin, idMat3 &axis ) {
	common->Error( "idEntity::GetPhysicsToSoundTransform(): stub called" );
	return false;
}

bool idEntity::Collide( const trace_t &collision, const idVec3 &velocity ) {
	common->Error( "idEntity::Collide(): stub called" );
	return false;
}

void idEntity::GetImpactInfo( idEntity *ent, int id, const idVec3 &point, impactInfo_t *info ) {
	common->Error( "idEntity::GetImpactInfo(): stub called" );
}

void idEntity::ApplyImpulse( idEntity *ent, int id, const idVec3 &point, const idVec3 &impulse ) {
	common->Error( "idEntity::ApplyImpulse(): stub called" );
}

void idEntity::AddForce( idEntity *ent, int id, const idVec3 &point, const idVec3 &force ) {
	common->Error( "idEntity::AddForce(): stub called" );
}

void idEntity::ActivatePhysics( idEntity *ent ) {
	common->Error( "idEntity::ActivatePhysics(): stub called" );
}

bool idEntity::IsAtRest( void ) const {
	common->Error( "idEntity::IsAtRest(): stub called" );
	return false;
}

int idEntity::GetRestStartTime( void ) const {
	common->Error( "idEntity::GetRestStartTime(): stub called" );
	return -1;
}

void idEntity::AddContactEntity( idEntity *ent ) {
	common->Error( "idEntity::AddContactEntity(): stub called" );
}

void idEntity::RemoveContactEntity( idEntity *ent ) {
	common->Error( "idEntity::RemoveContactEntity(): stub called" );
}

bool idEntity::CanDamage( const idVec3 &origin, idVec3 &damagePoint ) const {
	common->Error( "idEntity::CanDamage(): stub called" );
	return false;
}

void idEntity::Damage( idEntity *inflictor, idEntity *attacker, const idVec3 &dir, const char *damageDefName, const float damageScale, const int location ) {
	common->Error( "idEntity::Damage(): stub called" );
}

void idEntity::AddDamageEffect( const trace_t &collision, const idVec3 &velocity, const char *damageDefName ) {
	common->Error( "idEntity::AddDamageEffect(): stub called" );
}

void idEntity::DamageFeedback( idEntity *victim, idEntity *inflictor, int &damage ) {
	common->Error( "idEntity::DamageFeedback(): stub called" );
}

bool idEntity::Pain( idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location ) {
	common->Error( "idEntity::Pain(): stub called" );
	return false;
}

void idEntity::Killed( idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location ){
	common->Error( "idEntity::Killed(): stub called" );
}

bool idEntity::ShouldConstructScriptObjectAtSpawn( void ) const {
	common->Error( "idEntity::ShouldConstructScriptObjectAtSpawn(): stub called" );
	return false;
}

idThread * idEntity::ConstructScriptObject( void ) {
	common->Error( "idEntity::ConstructScriptObject(): stub called" );
	return NULL;
}

void idEntity::DeconstructScriptObject( void ) {
	common->Error( "idEntity::DeconstructScriptObject(): stub called" );
}

bool idEntity::HandleSingleGuiCommand( idEntity *entityGui, idLexer *src ) {
	common->Error( "idEntity::HandleSingleGuiCommand(): stub called" );
	return false;
}

void idEntity::Teleport( const idVec3 &origin, const idAngles &angles, idEntity *destination ) {
	common->Error( "idEntity::Teleport(): stub called" );
}

void idEntity::ShowEditingDialog( void ) {
	common->Error( "idEntity::ShowEditingDialog(): stub called" );
}

void idEntity::ClientPredictionThink( void ) {
	common->Error( "idEntity::ClientPredictionThink(): stub called" );
}

void idEntity::WriteToSnapshot( idBitMsgDelta &msg ) const {
	common->Error( "idEntity::WriteToSnapshot(): stub called" );
}

void idEntity::ReadFromSnapshot( const idBitMsgDelta &msg ) {
	common->Error( "idEntity::ReadFromSnapshot(): stub called" );
}

bool idEntity::ServerReceiveEvent( int event, int time, const idBitMsg &msg ) {
	common->Error( "idEntity::ServerReceiveEvent(): stub called" );
	return false;
}

bool idEntity::ClientReceiveEvent( int event, int time, const idBitMsg &msg ) {
	common->Error( "idEntity::ClientReceiveEvent(): stub called" );
	return false;
}

void idInventory::Clear( void ) {
	common->Error( "idInventory::Error(): stub called" );
}

idActor::~idActor() {
	common->Error( "idActor::~idActor(): stub called" );
}

idDragEntity::~idDragEntity() {
	common->Error( "idDragEntity::~idDragEntity(): stub called" );
}

idAFEntity_Gibbable::~idAFEntity_Gibbable() {
	common->Error( "idAFEntity_Gibbable::~idAFEntity_Gibbable(): stub called" );
}

idIK_Walk::~idIK_Walk() {
	common->Error( "idIK_Walk::~idIK_Walk(): stub called" );
}

idAnimState::~idAnimState() {
	common->Error( "idAnimState::~idAnimState(): stub called" );
}

idPlayerIcon::~idPlayerIcon() {
	common->Error( "idPlayerIcon::~idPlayerIcon(): stub called" );
}

idTypeInfo * idAFEntity_Gibbable::GetType(void)const  {
	common->Error( "stub called" );
	return NULL;
}

void idAFEntity_Base::Think(void) {
	common->Error( "stub called" );
}

void idAFEntity_Gibbable::Present(void) {
	common->Error( "stub called" );
}

void idAnimatedEntity::SetModel(char const *) {
	common->Error( "stub called" );
}

void idAFEntity_Base::FreeModelDef(void) {
	common->Error( "stub called" );
}

bool idAFEntity_Base::UpdateAnimationControllers(void) {
	common->Error( "stub called" );
	return false;
}

idAnimator * idAnimatedEntity::GetAnimator(void) {
	common->Error( "stub called" );
	return NULL;
}

bool idAFEntity_Base::GetPhysicsToVisualTransform(class idVec3 &,class idMat3 &) {
	common->Error( "stub called" );
	return false;
}

bool idAFEntity_Base::Collide(struct trace_s const &,class idVec3 const &) {
	common->Error( "stub called" );
	return false;
}

void idAFEntity_Base::GetImpactInfo(class idEntity *,int,class idVec3 const &,struct impactInfo_s *) {
	common->Error( "stub called" );
}

void idAFEntity_Base::ApplyImpulse(class idEntity *,int,class idVec3 const &,class idVec3 const &) {
	common->Error( "stub called" );
}

void idAFEntity_Base::AddForce(class idEntity *,int,class idVec3 const &,class idVec3 const &) {
	common->Error( "stub called" );
}

void idAFEntity_Gibbable::Damage(class idEntity *,class idEntity *,class idVec3 const &,char const *,float,int) {
	common->Error( "stub called" );
}

void idAnimatedEntity::AddDamageEffect(struct trace_s const &,class idVec3 const &,char const *) {
	common->Error( "stub called" );
}

void idAFEntity_Base::ShowEditingDialog(void) {
	common->Error( "stub called" );
}

void idAnimatedEntity::ClientPredictionThink(void) {
	common->Error( "stub called" );
}

bool idAnimatedEntity::ClientReceiveEvent(int,int,class idBitMsg const &) {
	common->Error( "stub called" );
	return false;
}

int idAnimatedEntity::GetDefaultSurfaceType(void)const  {
	common->Error( "stub called" );
	return -1;
}

bool idAFEntity_Base::LoadAF(void) {
	common->Error( "stub called" );
	return false;
}

void idAFEntity_Base::LinkCombat(void) {
	common->Error( "stub called" );
}

void idAFEntity_Base::UnlinkCombat(void) {
	common->Error( "stub called" );
}

void idAFEntity_Gibbable::SpawnGibs(class idVec3 const &,char const *) {
	common->Error( "stub called" );
}

void idAFEntity_Gibbable::Gib(class idVec3 const &,char const *) {
	common->Error( "stub called" );
}

idIK::~idIK(void) {
	common->Error( "stub called" );
}

bool idIK_Walk::Init(class idEntity *,char const *,class idVec3 const &) {
	common->Error( "stub called" );
	return false;
}

void idIK_Walk::Evaluate(void) {
	common->Error( "stub called" );
}

void idIK_Walk::ClearJointMods(void) {
	common->Error( "stub called" );
}

idTypeInfo * idActor::GetType(void)const  {
	common->Error( "stub called" );
	return NULL;
}

renderView_s * idActor::GetRenderView(void) {
	common->Error( "stub called" );
	return NULL;
}

void idActor::Hide(void) {
	common->Error( "stub called" );
}

void idActor::Show(void) {
	common->Error( "stub called" );
}

void idActor::ProjectOverlay(class idVec3 const &,class idVec3 const &,float,char const *) {
	common->Error( "stub called" );
}

bool idActor::UpdateAnimationControllers(void) {
	common->Error( "stub called" );
	return false;
}

bool idActor::GetPhysicsToVisualTransform(class idVec3 &,class idMat3 &) {
	common->Error( "stub called" );
	return false;
}

bool idActor::GetPhysicsToSoundTransform(class idVec3 &,class idMat3 &) {
	common->Error( "stub called" );
	return false;
}

void idActor::Damage(class idEntity *,class idEntity *,class idVec3 const &,char const *,float,int) {
	common->Error( "stub called" );
}

bool idActor::Pain(class idEntity *,class idEntity *,int,class idVec3 const &,int) {
	common->Error( "stub called" );
	return false;
}

bool idActor::ShouldConstructScriptObjectAtSpawn(void)const  {
	common->Error( "stub called" );
	return false;
}

idThread * idActor::ConstructScriptObject(void) {
	common->Error( "stub called" );
	return NULL;
}

void idActor::Teleport(class idVec3 const &,class idAngles const &,class idEntity *) {
	common->Error( "stub called" );
}

int idActor::GetDefaultSurfaceType(void)const  {
	common->Error( "stub called" );
	return -1;
}

bool idActor::LoadAF(void) {
	common->Error( "stub called" );
	return false;
}

void idActor::LinkCombat(void) {
	common->Error( "stub called" );
}

void idActor::UnlinkCombat(void) {
	common->Error( "stub called" );
}

void idActor::SpawnGibs(idVec3 const &,char const *) {
	common->Error( "stub called" );
}

void idActor::Gib(idVec3 const &,char const *) {
	common->Error( "stub called" );
}

void idActor::Restart(void) {
	common->Error( "stub called" );
}

void idActor::GetViewPos(class idVec3 &,class idMat3 &)const  {
	common->Error( "stub called" );
}

void idActor::GetAIAimTargets(class idVec3 const &,class idVec3 &,class idVec3 &) {
	common->Error( "stub called" );
}

bool idActor::OnLadder(void)const  {
	common->Error( "stub called" );
	return false;
}

void idActor::GetAASLocation(class idAAS *,class idVec3 &,int &)const  {
	common->Error( "stub called" );
}

idTypeInfo * idPlayer::GetType(void)const  {
	common->Error( "stub called" );
	return NULL;
}

renderView_s * idPlayer::GetRenderView(void) {
	common->Error( "stub called" );
	return NULL;
}

void idPlayer::Think(void) {
	common->Error( "stub called" );
}

void idPlayer::Hide(void) {
	common->Error( "stub called" );
}

void idPlayer::Show(void) {
	common->Error( "stub called" );
}

bool idPlayer::GetPhysicsToVisualTransform(class idVec3 &,class idMat3 &) {
	return false;
}

bool idPlayer::GetPhysicsToSoundTransform(class idVec3 &,class idMat3 &) {
	common->Error( "stub called" );
	return false;
}

bool idPlayer::Collide(struct trace_s const &,class idVec3 const &) {
	common->Error( "stub called" );
	return false;
}

void idPlayer::Damage(class idEntity *,class idEntity *,class idVec3 const &,char const *,float,int) {
	common->Error( "stub called" );
}

void idPlayer::DamageFeedback(class idEntity *,class idEntity *,int &) {
	common->Error( "stub called" );
}

void idPlayer::Killed(class idEntity *,class idEntity *,int,class idVec3 const &,int) {
	common->Error( "stub called" );
}

bool idPlayer::HandleSingleGuiCommand(class idEntity *,class idLexer *) {
	common->Error( "stub called" );
	return false;
}

void idPlayer::Teleport(class idVec3 const &,class idAngles const &,class idEntity *) {
	common->Error( "stub called" );
}

void idPlayer::ClientPredictionThink(void) {
	common->Error( "stub called" );
}

void idPlayer::WriteToSnapshot(class idBitMsgDelta &)const  {
	common->Error( "stub called" );
}

void idPlayer::ReadFromSnapshot(class idBitMsgDelta const &) {
	common->Error( "stub called" );
}

bool idPlayer::ServerReceiveEvent(int,int,class idBitMsg const &) {
	common->Error( "stub called" );
	return false;
}

bool idPlayer::ClientReceiveEvent(int,int,class idBitMsg const &) {
	common->Error( "stub called" );
	return false;
}

void idPlayer::Restart(void) {
	common->Error( "stub called" );
}

void idPlayer::GetViewPos(class idVec3 &,class idMat3 &)const  {
	common->Error( "stub called" );
}

void idPlayer::GetAIAimTargets(idVec3 const &,class idVec3 &,class idVec3 &) {
	common->Error( "stub called" );
}

bool idPlayer::OnLadder(void)const  {
	common->Error( "stub called" );
	return false;
}

void idPlayer::GetAASLocation( idAAS *, idVec3 &,int & )const  {
	common->Error( "stub called" );
}

void idPlayer::UpdatePlayerIcons( void ) {
	common->Error( "stub called" );
}

void idPlayer::DrawPlayerIcons( void ) {
	common->Error( "stub called" );
}

void idPlayer::HidePlayerIcons( void ) {
	common->Error( "idPlayer::HidePlayerIcons(): stub called" );
}

idAFEntity_Base::~idAFEntity_Base(void) {
	common->Error( "stub called" );
}

bool idIK::Init(class idEntity *,char const *,class idVec3 const &) {
	common->Error( "stub called" );
	return false;
}

void idIK::Evaluate(void) {
	common->Error( "stub called" );
}

void idIK::ClearJointMods(void) {
	common->Error( "stub called" );
}

idAnimatedEntity::~idAnimatedEntity() {
	common->Error( "stub called" );
}

idAF::~idAF() {
	common->Error( "stub called" );
}

idTypeInfo * idAFEntity_Base::GetType(void)const {
	common->Error( "stub called" );
	return NULL;
}

idPhysics_AF::~idPhysics_AF(void) {
	common->Error( "stub called" );
}

idAnimator::~idAnimator(void) {
	common->Error( "stub called" );
}

idTypeInfo * idAnimatedEntity::GetType(void)const {
	common->Error( "stub called" );
	return NULL;
}

void idAnimatedEntity::Think(void) {
	common->Error( "stub called" );
}

idPlayer::~idPlayer() {
	common->Error( "idPlayer::~idPlayer(): stub called" );
}

class idTypeInfo * idPhysics_AF::GetType(void)const {
	common->Error( "stub called" );
	return NULL;
}

void idPhysics_AF::SetClipModel(class idClipModel *,float,int,bool){
	common->Error( "stub called" );
}

class idClipModel * idPhysics_AF::GetClipModel(int)const {
	common->Error( "stub called" );
	return NULL;
}

int idPhysics_AF::GetNumClipModels(void)const {
	common->Error( "stub called" );
	return -1;
}

void idPhysics_AF::SetMass(float,int){
	common->Error( "stub called" );
}

float idPhysics_AF::GetMass(int)const {
	common->Error( "stub called" );
	return -1;
}

void idPhysics_AF::SetContents(int,int){
	common->Error( "stub called" );
}

int idPhysics_AF::GetContents(int)const {
	common->Error( "stub called" );
	return -1;
}

const idBounds &idPhysics_AF::GetBounds(int)const {
	common->Error( "stub called" );
	return *( idBounds * )NULL;
}

const idBounds &idPhysics_AF::GetAbsBounds(int)const {
	common->Error( "stub called" );
	return *( idBounds * )NULL;
}

bool idPhysics_AF::Evaluate(int,int){
	common->Error( "stub called" );
	return false;
}

void idPhysics_AF::UpdateTime(int){
	common->Error( "stub called" );
}

int idPhysics_AF::GetTime(void)const {
	common->Error( "stub called" );
	return -1;
}

void idPhysics_AF::GetImpactInfo(int,class idVec3 const &,struct impactInfo_s *)const {
	common->Error( "stub called" );
}

void idPhysics_AF::ApplyImpulse(int,class idVec3 const &,class idVec3 const &){
	common->Error( "stub called" );
}

void idPhysics_AF::AddForce(int,class idVec3 const &,class idVec3 const &){
	common->Error( "stub called" );
}

void idPhysics_AF::Activate(void){
	common->Error( "stub called" );
}

void idPhysics_AF::PutToRest(void){
	common->Error( "stub called" );
}

bool idPhysics_AF::IsAtRest(void)const {
	common->Error( "stub called" );
	return false;
}

int idPhysics_AF::GetRestStartTime(void)const {
	common->Error( "stub called" );
	return -1;
}

bool idPhysics_AF::IsPushable(void)const {
	common->Error( "stub called" );
	return false;
}

void idPhysics_AF::SaveState(void){
	common->Error( "stub called" );
}

void idPhysics_AF::RestoreState(void){
	common->Error( "stub called" );
}

void idPhysics_AF::SetOrigin(class idVec3 const &,int){
	common->Error( "stub called" );
}

void idPhysics_AF::SetAxis(class idMat3 const &,int){
	common->Error( "stub called" );
}

void idPhysics_AF::Translate(class idVec3 const &,int){
	common->Error( "stub called" );
}

void idPhysics_AF::Rotate(class idRotation const &,int){
	common->Error( "stub called" );
}

const idVec3 & idPhysics_AF::GetOrigin(int)const {
	common->Error( "stub called" );
	return *( idVec3 *) NULL;
}

const idMat3 & idPhysics_AF::GetAxis(int)const {
	common->Error( "stub called" );
	return *( idMat3 *) NULL;
}

void idPhysics_AF::SetLinearVelocity(class idVec3 const &,int){
	common->Error( "stub called" );
}

void idPhysics_AF::SetAngularVelocity(class idVec3 const &,int){
	common->Error( "stub called" );
}

const idVec3 & idPhysics_AF::GetLinearVelocity(int)const {
	common->Error( "stub called" );
	return *( idVec3 *) NULL;
}

const idVec3 & idPhysics_AF::GetAngularVelocity(int)const {
	common->Error( "stub called" );
	return *( idVec3 *) NULL;
}

void idPhysics_AF::ClipTranslation(struct trace_s &,const idVec3 &,const idClipModel *)const {
	common->Error( "stub called" );
}

void idPhysics_AF::ClipRotation(struct trace_s &,const idRotation &,const idClipModel *)const {
	common->Error( "stub called" );
}

int idPhysics_AF::ClipContents(const idClipModel *)const {
	common->Error( "stub called" );
	return -1;
}

void idPhysics_AF::DisableClip(void){
	common->Error( "stub called" );
}

void idPhysics_AF::EnableClip(void){
	common->Error( "stub called" );
}

void idPhysics_AF::UnlinkClip(void){
	common->Error( "stub called" );
}

void idPhysics_AF::LinkClip(void){
	common->Error( "stub called" );
}

bool idPhysics_AF::EvaluateContacts(void){
	common->Error( "stub called" );
	return false;
}

void idPhysics_AF::SetMaster(class idEntity *,bool){
	common->Error( "stub called" );
}

void idPhysics_AF::SetPushed(int){
	common->Error( "stub called" );
}

const idVec3 & idPhysics_AF::GetPushedLinearVelocity(int)const {
	common->Error( "stub called" );
	return *( idVec3 * ) NULL;
}

const idVec3  & idPhysics_AF::GetPushedAngularVelocity(int)const {
	common->Error( "stub called" );
	return *( idVec3 * ) NULL;
}

void idPhysics_AF::WriteToSnapshot(class idBitMsgDelta &)const {
	common->Error( "stub called" );
}

void idPhysics_AF::ReadFromSnapshot(class idBitMsgDelta const &){
	common->Error( "stub called" );
}
