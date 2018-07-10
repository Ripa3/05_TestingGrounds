// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "BoundsPool")
	void PopulateBoundsPool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:

	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
	
};
