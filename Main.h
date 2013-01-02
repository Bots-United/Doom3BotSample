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

#ifndef __MAIN_H__
#define __MAIN_H__

#include "../idlib/precompiled.h"

#ifndef ID_TIME_T
#define ID_TIME_T unsigned
#endif

#include "../game/Pvs.h"
#include "../game/ai/AAS.h"
#include "../game/gamesys/Event.h"
#include "../game/gamesys/Class.h"
#include "../game/gamesys/SaveGame.h"
#include "../game/physics/Clip.h"

#include "EngineAPI.h"
#include "GameAPI.h"
#include "Export.h"
#include "Unzip.h"

#include "BotFacade.h"
#include "SysCmds.h"

#include "Adapter.h"
#include "Adapter_D3.h"

#include "BotCommon.h"

#include "Bot.h"
#include "Bot_D3.h"

#include "BotService.h"
#include "BotService_D3.h"

#ifdef _WIN32
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#endif

#include <ctype.h>

#endif
