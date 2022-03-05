// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CableComponent.h"
#include "ChainComponent.generated.h"

/**
 * 
 */
UCLASS()
class JAM_API UChainComponent : public UCableComponent
{
	GENERATED_BODY()
	
public:
	UChainComponent(const FObjectInitializer& ObjectInitializer);
};
