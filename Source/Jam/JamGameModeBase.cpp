// Copyright Epic Games, Inc. All Rights Reserved.


#include "JamGameModeBase.h"
#include "JamLevelStart.h"

AJamGameModeBase::AJamGameModeBase()
{
    LevelStartClass = AJamLevelStart::StaticClass();
}
