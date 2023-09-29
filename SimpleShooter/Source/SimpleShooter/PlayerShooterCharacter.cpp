// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerShooterCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"
#include "ShooterGameModeBase.h"

// Sets default values
APlayerShooterCharacter::APlayerShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerShooterCharacter::BeginPlay()
{
	Super::BeginPlay();	
	
	ShooterCharacterController = Cast<APlayerController>(GetController());

	if(ShooterCharacterController)
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(ShooterCharacterController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ShooterMappingContext, 0);
		}
	}
}

void APlayerShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &APlayerShooterCharacter::Move);
		EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &APlayerShooterCharacter::Look);
		EnhancedInputComponent->BindAction(LookRateInputAction, ETriggerEvent::Triggered, this, &APlayerShooterCharacter::LookRate);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(FireInputAction, ETriggerEvent::Started, this, &AShooterCharacter::FireGun);
	}
}

float APlayerShooterCharacter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

void APlayerShooterCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MoveValue = Value.Get<FVector2D>();

	if (MoveValue.Y != 0)
	{
		AddMovementInput(GetActorForwardVector() * MoveValue.Y);
	}

	if (MoveValue.X != 0)
	{
		AddMovementInput(GetActorRightVector() * MoveValue.X);
	}
}

void APlayerShooterCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if (LookValue.Y != 0)
	{
		AddControllerPitchInput(LookValue.Y);
	}

	if (LookValue.X != 0)
	{
		AddControllerYawInput(LookValue.X);
	}
}

void APlayerShooterCharacter::LookRate(const FInputActionValue& Value)
{
	FVector2D LookValue = Value.Get<FVector2D>();

	if (LookValue.Y != 0)
	{
		AddControllerPitchInput(LookRotationRate * LookValue.Y * GetWorld()->GetDeltaSeconds());
	}

	if (LookValue.X != 0)
	{
		AddControllerYawInput(LookRotationRate * LookValue.X * GetWorld()->GetDeltaSeconds());
	}
}
