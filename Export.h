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

#ifndef H_EXPORT_H
#define H_EXPORT_H

extern idSys *						sys;
extern idCommon *					common;
extern idCmdSystem *				cmdSystem;
extern idCVarSystem *				cvarSystem;
extern idFileSystem *				fileSystem;
extern idNetworkSystem *			networkSystem;
extern idRenderSystem *				renderSystem;
extern idSoundSystem *				soundSystem;
extern idRenderModelManager *		renderModelManager;
extern idUserInterfaceManager *		uiManager;
extern idDeclManager *				declManager;
extern idAASFileManager *			AASFileManager;
extern idCollisionModelManager *	collisionModelManager;

extern idRenderWorld *				gameRenderWorld;
extern idSoundWorld *				gameSoundWorld;

extern idGame *						game;

extern gameExport_t					gameExport;

#endif
