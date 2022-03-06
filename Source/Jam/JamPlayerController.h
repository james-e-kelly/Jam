// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FMODBlueprintStatics.h"
#include "JamPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class JAM_API AJamPlayerController : public APlayerController
{
	GENERATED_BODY()
    
protected:
	
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* MenuMusic;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* CinematicMusic;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* GameplayMusic;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UFMODEvent* ThemeMusic;
    
public:
    
    UFUNCTION(BlueprintCallable)
    void PlayMenuMusic();
    
    UFUNCTION(BlueprintCallable)
    void PlayCinematicMusic();
    
    UFUNCTION(BlueprintCallable)
    void PlayGameplayMusic();
    
    UFUNCTION(BlueprintCallable)
    void PlayThemeMusic();
    
    UFUNCTION(BlueprintCallable)
    void StopMusic();
    
    virtual void BeginPlay() override;
    
private:
    
    FMOD::Studio::EventInstance* PlayEvent(UFMODEvent* Event);
    
    void StopAndReleaseEvent(FMOD::Studio::EventInstance* Instance);
    
    FMOD::Studio::EventInstance* MenuMusicInstance;
    FMOD::Studio::EventInstance* GameplayMusicInstance;
    FMOD::Studio::EventInstance* ThemeMusicInstance;
    FMOD::Studio::EventInstance* CinematicMusicInstance;
};
