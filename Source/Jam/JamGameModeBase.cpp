

#include "JamGameModeBase.h"
#include "JamLevelStart.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "ChainComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

AJamGameModeBase::AJamGameModeBase()
{
    LevelStartClass = AJamLevelStart::StaticClass();
    MaxDistanceAllowed = 10.f; // should we make this really big or really small? :thinking:
}

void AJamGameModeBase::StartPlay()
{
    Super::StartPlay();
    
    PlayerCharacter = Cast<ATP_ThirdPersonCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
    check(PlayerCharacter); // should only use this character
    
    if (PlayerCharacter)
    {
        PlayerCharacter->OnCableConnectionAdded.AddDynamic(this, &AJamGameModeBase::OnCharacterCreateChain);
    }
    
    TActorIterator<AJamLevelStart> StartIterator = TActorIterator<AJamLevelStart>(GetWorld());
    for (StartIterator; StartIterator; ++StartIterator )
    {
        if (StartIterator->GetClass() == *LevelStartClass)
        {
            LevelStart = *StartIterator;
            break;
        }
    }
    
    if (LevelStart)
    {
        MaxDistanceAllowed = LevelStart->MaxDistanceAllowed;
    }
}

void AJamGameModeBase::OnCharacterCreateChain(ATP_ThirdPersonCharacter* Character, UChainComponent* ChainComponentAdded)
{
    float CurrentLength = PlayerCharacter->GetTotalChainLengthUsed();
    
    UE_LOG(LogClass, Warning, TEXT("CHAIN: New length %f"), CurrentLength);
    
    if (CurrentLength >= MaxDistanceAllowed)
    {
        UE_LOG(LogClass, Error, TEXT("LEVEL OVER: We ran out of chain"))
    }
}
