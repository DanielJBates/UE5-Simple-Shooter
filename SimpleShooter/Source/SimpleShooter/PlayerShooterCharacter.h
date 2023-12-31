// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterCharacter.h"

#include "PlayerShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class AGunActor;

UCLASS()
class SIMPLESHOOTER_API APlayerShooterCharacter : public AShooterCharacter
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
	UInputAction* LookRateInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* JumpInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	UInputAction* FireInputAction;

	UPROPERTY(EditAnywhere, Category = "Player Input");
	float LookRotationRate = 100;

public:
	APlayerShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

private:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void LookRate(const FInputActionValue& Value);
};
