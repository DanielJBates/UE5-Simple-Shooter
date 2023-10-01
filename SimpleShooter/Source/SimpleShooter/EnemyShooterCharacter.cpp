// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShooterCharacter.h"

void AEnemyShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PatrolPathNodes.Num() <= 0)
	{
		PatrolTargetLocation = GetActorLocation();
	}
	else
	{
		PatrolTargetLocation = PatrolPathNodes[0];
	}
}

void AEnemyShooterCharacter::UpdatePatrolTargetLocation()
{
	if (PatrolPathNodes.Num() <= 0) return;

	if (PatrolTargetIndex == PatrolPathNodes.Num() - 1)
	{
		PatrolTargetIndex = 0;
	}
	else
	{
		++PatrolTargetIndex;
	}

	PatrolTargetLocation = PatrolPathNodes[PatrolTargetIndex];
}
