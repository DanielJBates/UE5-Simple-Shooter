// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterCharacter.h"

#include "EnemyShooterCharacter.generated.h"

class UPawnSensingComponent;

UCLASS()
class SIMPLESHOOTER_API AEnemyShooterCharacter : public AShooterCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol", Meta = (MakeEditWidget = true))
	TArray<FVector> PatrolPathNodes;

	//Patrol path will loop in the following ways:
	// 0 being the first node and 2 being the last node
	//True: (Node 0, Node 1, Node 2, Node 1, Node 0, Node 1, Node 2 etc)
	//False: (Node 0, Node 1, Node 2, Node 0, Node 1, Node 2 etc)
	UPROPERTY(EditInstanceOnly, Category = "Patrol")
	bool bBacktrackLoop = false; 

	bool bForwardPatrol = true;

	int PatrolTargetIndex = 0;
	FVector PatrolTargetLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void UpdatePatrolTargetLocation();
	FVector GetPatrolTargetLocation() const { return PatrolTargetLocation; }
};
