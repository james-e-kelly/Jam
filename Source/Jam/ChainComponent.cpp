// Fill out your copyright notice in the Description page of Project Settings.


#include "ChainComponent.h"

UChainComponent::UChainComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	bTickInEditor = true;
	bAutoActivate = true;

	bAttachStart = true;
	bAttachEnd = true;
	bEnableCollision = true;
	CableWidth = 10.f;
	NumSegments = 20;
	NumSides = 4;
	EndLocation = FVector(100.f, 0, 0);
	CableLength = 100.f;
	SubstepTime = 0.02f;
	TileMaterial = 1.f;
	CollisionFriction = 0.2f;
	CableGravityScale = 1.f;

	SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	SetUseCCD(true);

	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Art/Materials/M_Master_RopeEmissive.M_Master_RopeEmissive'"));
	if (Material.Object)
	{
		SetMaterial(0, Material.Object);
	}
}

