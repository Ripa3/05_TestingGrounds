// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* InPool);


	UFUNCTION(BlueprintCallable, Category = "null")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn = 1, int32 MaxSpawn = 1, float Radius = 500.f, float MinScale =1, float MaxScale = 1);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset = FVector(2000.f, 0.f, 0.f);


	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent = FVector(0.f, -1600.f, 80.f);
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent = FVector(4000.f, 2100.f, 80.f);

private:

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale);

	bool CanSpawnAtLocation(FVector Location, float Radius);

	void PositionNavMeshBoundsVolume();
	
	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
};
