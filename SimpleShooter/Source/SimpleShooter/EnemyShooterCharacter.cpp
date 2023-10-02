// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShooterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AEnemyShooterCharacter::AEnemyShooterCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensor = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensor"));
}

void AEnemyShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PatrolPathNodes.Num() <= 0)
	{
		PatrolTargetLocation = GetActorLocation();
	}
	else
	{
		for (int i = 0; i < PatrolPathNodes.Num(); i++)
		{
			PatrolPathNodes[i] = UKismetMathLibrary::TransformLocation(GetActorTransform(), PatrolPathNodes[i]);
		}
		
		PatrolTargetLocation = PatrolPathNodes[0];
	}
}

void AEnemyShooterCharacter::UpdatePatrolTargetLocation()
{
	if (PatrolPathNodes.Num() <= 0) return;

	if (bBacktrackLoop)
	{
		if ((PatrolTargetIndex == PatrolPathNodes.Num() - 1 && bForwardPatrol) || (PatrolTargetIndex == 0 && !bForwardPatrol))
		{
			bForwardPatrol = !bForwardPatrol;
		}

		if (bForwardPatrol)
		{
			++PatrolTargetIndex;
		}
		else
		{
			--PatrolTargetIndex;
		}
	}
	else
	{
		if (PatrolTargetIndex == PatrolPathNodes.Num() - 1)
		{
			PatrolTargetIndex = 0;
		}
		else
		{
			++PatrolTargetIndex;
		}
	}

	PatrolTargetLocation = PatrolPathNodes[PatrolTargetIndex];
}
