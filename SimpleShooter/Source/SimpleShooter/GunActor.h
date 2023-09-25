// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GunActor.generated.h"

class AController;

UCLASS()
class SIMPLESHOOTER_API AGunActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* GunRoot;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* HitWorldFlash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* HitPawnFlash;

	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.0f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.0f;

public:	
	// Sets default values for this actor's properties
	AGunActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire();

private:
	bool GunTrace(FHitResult& OutHitResult, FVector& OutShotDirection);

	AController* GetOwnerController() const;
};
