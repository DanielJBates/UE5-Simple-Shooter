// Fill out your copyright notice in the Description page of Project Settings.

#include "GunActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

#include "DrawDebugHelpers.h"

// Sets default values
AGunActor::AGunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GunRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Gun Root"));
	RootComponent = GunRoot;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	Mesh->SetupAttachment(GunRoot);
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunActor::Fire()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(!OwnerPawn) return;

	AController* OwnerController = OwnerPawn->GetController();
	if(!OwnerController) return;

	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

	FVector End = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;

	FHitResult Hit;

	if(GetWorld()->LineTraceSingleByChannel(Hit, ViewPointLocation, End, ECollisionChannel::ECC_GameTraceChannel1))
	{
		DrawDebugPoint(GetWorld(), ViewPointLocation, 20, FColor::Green, true);
		DrawDebugPoint(GetWorld(), Hit.ImpactPoint, 20, FColor::Red, true);
		DrawDebugLine(GetWorld(), ViewPointLocation, Hit.ImpactPoint, FColor::Blue, true);

		FVector ShotDirection = -ViewPointRotation.Vector();

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitFlash, Hit.ImpactPoint, ShotDirection.Rotation());
	}
}