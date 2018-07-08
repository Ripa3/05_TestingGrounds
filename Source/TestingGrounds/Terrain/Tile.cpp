// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn, int32 MaxSpawn, float Radius)
{
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint = GetEmptyLocation(Radius);
		PlaceActor(ToSpawn, SpawnPoint);
	}
}

FVector ATile::GetEmptyLocation(float Radius)
{
	FVector Min = FVector(81.f, -1718.f, 80.f);
	FVector Max = FVector(3837.f, 1984.f, 80.f);
	FBox Bounds(Min, Max);

	FVector SpawnPoint;
	do
	{
		SpawnPoint = FMath::RandPointInBox(Bounds);
		CastSphere(SpawnPoint, 300.f);
	} while (CastSphere(SpawnPoint, 300.f));

	return SpawnPoint;
}

void ATile::PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}


bool ATile::CastSphere(FVector Location, float Radius)
{
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Location,
		Location,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);
	FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	DrawDebugCapsule(GetWorld(), Location, 0, Radius, FQuat::Identity, ResultColor, true, 100.f);
	return HasHit;
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();

	CastSphere(GetActorLocation(), 300.f);
	CastSphere(GetActorLocation() + FVector(0.f, 0.f, 3000.f), 300.f);

}


// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

