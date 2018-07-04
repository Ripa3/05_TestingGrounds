// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "../Weapons/Gun.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create and setup the CameraComponent
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f);
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//Create and setup MeshComponent
	MeshFP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	MeshFP->SetupAttachment(FirstPersonCameraComponent);
	MeshFP->SetOnlyOwnerSee(true);
	MeshFP->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
	MeshFP->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	MeshFP->bCastDynamicShadow = false;
	MeshFP->CastShadow = false;
}

void AMannequin::Fire()
{
	Gun->OnFire();
}

// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();
	if (ensure(GunBlueprint != NULL))
	{
		Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
		Gun->AttachToComponent(MeshFP, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		Gun->AnimInstance = MeshFP->GetAnimInstance();
	}
	
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

