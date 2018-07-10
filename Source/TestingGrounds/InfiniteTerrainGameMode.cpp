// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "ActorPool.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume"));
}

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
	NavMeshBoundsVolumePool->Add(VolumeToAdd);

}
