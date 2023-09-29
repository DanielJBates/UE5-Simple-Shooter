// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "ShooterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class AGunActor;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	APlayerController* ShooterCharacterController;

	UPROPERTY(EditDefaultsOnly, Category = "Classes")
	TSubclassOf<AGunActor> GunActorClass;

	AGunActor* GunActor;

protected:
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere)
	float Health;
public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsAlive() const;
	
	void FireGun();
};
