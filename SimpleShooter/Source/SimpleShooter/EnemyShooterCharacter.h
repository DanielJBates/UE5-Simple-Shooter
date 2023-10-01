// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterCharacter.h"

#include "EnemyShooterCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API AEnemyShooterCharacter : public AShooterCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<FVector> PatrolPathNodes;

	int PatrolTargetIndex = 0;
	FVector PatrolTargetLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void UpdatePatrolTargetLocation();
	FVector GetPatrolTargetLocation() const { return PatrolTargetLocation; }
};
