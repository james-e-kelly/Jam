// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JamLevelStart.generated.h"

/**
 * Start of the level and lets the GameMode know about win conditions for the level
 */
UCLASS()
class JAM_API AJamLevelStart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJamLevelStart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
public:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxDistanceAllowed = 1000.f;

};
