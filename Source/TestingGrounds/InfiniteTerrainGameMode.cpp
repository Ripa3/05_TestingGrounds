// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"

void AInfiniteTerrainGameMode::PopulateBoundsPool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume * VolumeToAdd)
{
	UE_LOG(LogTemp, Warning, TEXT("Volume To Add: %s"), *VolumeToAdd->GetName());
}
