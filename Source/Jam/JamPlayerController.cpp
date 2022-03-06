// Fill out your copyright notice in the Description page of Project Settings.


#include "JamPlayerController.h"

void AJamPlayerController::PlayMenuMusic()
{
    StopMusic();
    MenuMusicInstance = PlayEvent(MenuMusic);
}

void AJamPlayerController::PlayGameplayMusic()
{
    StopMusic();
    GameplayMusicInstance = PlayEvent(GameplayMusic);
}

void AJamPlayerController::PlayCinematicMusic()
{
    StopMusic();
    CinematicMusicInstance = PlayEvent(CinematicMusic);
}

void AJamPlayerController::PlayThemeMusic()
{
    StopMusic();
    ThemeMusicInstance = PlayEvent(ThemeMusic);
}

void AJamPlayerController::StopMusic()
{
    StopAndReleaseEvent(MenuMusicInstance);
    StopAndReleaseEvent(GameplayMusicInstance);
    StopAndReleaseEvent(ThemeMusicInstance);
    StopAndReleaseEvent(CinematicMusicInstance);
}

void AJamPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    PlayThemeMusic();
}

FMOD::Studio::EventInstance* AJamPlayerController::PlayEvent(UFMODEvent* Event)
{
    FFMODEventInstance PlayingInstance = UFMODBlueprintStatics::PlayEvent2D(this, Event, false);
    
    if (PlayingInstance.Instance != nullptr)
    {
        PlayingInstance.Instance->start();
    }
    
    return PlayingInstance.Instance;
}

void AJamPlayerController::StopAndReleaseEvent(FMOD::Studio::EventInstance* Instance)
{
    if (Instance)
    {
        Instance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
        Instance->release();
    }
}
