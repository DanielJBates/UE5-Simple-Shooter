// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "GunActor.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"
#include "ShooterGameModeBase.h"


// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	GunActor = GetWorld()->SpawnActor<AGunActor>(GunActorClass);
	GunActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	GunActor->SetOwner(this);

	Health = MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApplied = FMath::Min(Health, DamageToApplied);
	Health -= DamageToApplied;

	if(!IsAlive())
	{	
		AShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AShooterGameModeBase>();
		if(GameMode)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	return DamageToApplied;
}

void AShooterCharacter::FireGun()
{
	GunActor->Fire();
}

bool AShooterCharacter::IsAlive() const
{
	if(Health <= 0.0f) return false;

	return true;
}