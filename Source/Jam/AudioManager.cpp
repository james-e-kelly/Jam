// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioManager.h"

void AAudioManager::PlayMenuMusic()
{
    StopAndReleaseEvent(GameplayMusicInstance);
    PlayEvent(MenuMusic);
}

void AAudioManager::PlayGameplayMusic()
{
    StopAndReleaseEvent(MenuMusicInstance);
    PlayEvent(GameplayMusic);
}

FMOD::Studio::EventInstance* AAudioManager::PlayEvent(UFMODEvent* Event)
{
    FFMODEventInstance PlayingInstance = UFMODBlueprintStatics::PlayEvent2D(this, Event, false);
    
    if (PlayingInstance.Instance != nullptr)
    {
        PlayingInstance.Instance->start();
    }
    
    return PlayingInstance.Instance;
}

void AAudioManager::StopAndReleaseEvent(FMOD::Studio::EventInstance* Instance)
{
    if (Instance)
    {
        Instance->stop(FMOD_STUDIO_STOP_ALLOWFADEOUT);
        Instance->release();
    }
}
