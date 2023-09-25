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

	ShooterCharacterController = Cast<APlayerController>(GetController());

	if(ShooterCharacterController)
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ShooterCharacterController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ShooterMappingContext, 0);
		}
	}

	Health = MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Move);
		EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Look);
		EnhancedInputComponent->BindAction(LookRateInputAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookRate);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(FireInputAction, ETriggerEvent::Started, this, &AShooterCharacter::FireGun);
    }
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

void AShooterCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveValue = Value.Get<FVector2D>();

	if(MoveValue.Y != 0)
	{
		AddMovementInput(GetActorForwardVector() * MoveValue.Y);
	}

	if(MoveValue.X != 0)
	{
		AddMovementInput(GetActorRightVector() * MoveValue.X);
	}
}

void AShooterCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if(LookValue.Y != 0)
	{	
		AddControllerPitchInput(LookValue.Y);
	}

	if(LookValue.X != 0)
	{
		AddControllerYawInput(LookValue.X);
	}
}

void AShooterCharacter::LookRate(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if(LookValue.Y != 0)
	{	
		AddControllerPitchInput(LookRotationRate * LookValue.Y * GetWorld()->GetDeltaSeconds());
	}

	if(LookValue.X != 0)
	{
		AddControllerYawInput(LookRotationRate * LookValue.X * GetWorld()->GetDeltaSeconds());
	}
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
