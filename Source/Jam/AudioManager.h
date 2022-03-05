// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FMODBlueprintStatics.h"
#include "AudioManager.generated.h"

class UFMODEvent;

/**
 * Gonna handle all the top level audio playing like music and such
 */
UCLASS(Blueprintable)
class JAM_API AAudioManager : public AInfo
{
	GENERATED_BODY()
    
protected:
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* MenuMusic;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* GameplayMusic;
    
protected:
    
    FMOD::Studio::EventInstance* MenuMusicInstance;
    
    FMOD::Studio::EventInstance* GameplayMusicInstance;
    
public:
    
    UFUNCTION(BlueprintCallable)
    void PlayMenuMusic();
    
    UFUNCTION(BlueprintCallable)
    void PlayGameplayMusic();
    
private:
    
    FMOD::Studio::EventInstance* PlayEvent(UFMODEvent* Event);
    
    void StopAndReleaseEvent(FMOD::Studio::EventInstance* Instance);
};
