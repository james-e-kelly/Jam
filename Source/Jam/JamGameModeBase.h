// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JamGameModeBase.generated.h"

class AJamLevelStart;

/**
 * 
 */
UCLASS()
class JAM_API AJamGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
    
    
    
public:
    
    AJamGameModeBase();
    
    TSubclassOf<AJamLevelStart> LevelStartClass;
	
};
