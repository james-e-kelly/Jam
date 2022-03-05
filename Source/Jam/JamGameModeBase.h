
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JamGameModeBase.generated.h"

class AJamLevelStart;
class ATP_ThirdPersonCharacter;
class UCableComponent;

/**
 * 
 */
UCLASS()
class JAM_API AJamGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
    
public:
    
    AJamGameModeBase();
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<AJamLevelStart> LevelStartClass;
    
protected:
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    ATP_ThirdPersonCharacter* PlayerCharacter;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    AJamLevelStart* LevelStart;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    float MaxDistanceAllowed;
    
    UFUNCTION()
    void OnCharacterCreateCable(ATP_ThirdPersonCharacter* Character, UCableComponent* CableComponentAdded);
    
public:
    
    virtual void StartPlay() override;
	
};
