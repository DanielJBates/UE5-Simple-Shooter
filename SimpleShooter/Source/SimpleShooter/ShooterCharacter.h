// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "ShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	APlayerController* ShooterCharacterController;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputMappingContext* ShooterMappingContext;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* LookInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* JumpInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* FireInputAction;

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};