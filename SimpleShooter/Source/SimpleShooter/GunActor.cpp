// Fill out your copyright notice in the Description page of Project Settings.

#include "GunActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"

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
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));

	FHitResult Hit;
	FVector ShotDirection;

	if(!GunTrace(Hit, ShotDirection)) return;

	if(Cast<APawn>(Hit.GetActor()))
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitPawnFlash, Hit.ImpactPoint, ShotDirection.Rotation());
	}
	else
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitWorldFlash, Hit.ImpactPoint, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HitSound, Hit.ImpactPoint);
	}

	AController* OwnerController = GetOwnerController();
	if(!OwnerController) return;

	if(AActor* HitActor = Hit.GetActor())
	{
		FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
		HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
	}
}

bool AGunActor::GunTrace(FHitResult& OutHitResult, FVector& OutShotDirection)
{
	AController* OwnerController = GetOwnerController();
	if(!OwnerController) return false;

	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

	OutShotDirection = -ViewPointRotation.Vector();

	FVector End = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(OutHitResult, ViewPointLocation, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGunActor::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(!OwnerPawn) return nullptr;

	return OwnerPawn->GetController();
}