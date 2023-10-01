// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PatrolTargetLocation.h"
#include "AIController.h"
#include "EnemyShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_PatrolTargetLocation::UBTTask_PatrolTargetLocation()
{
	NodeName = TEXT("Update Patrol Target Location");
}

EBTNodeResult::Type UBTTask_PatrolTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyShooterCharacter* EnemyCharacter = Cast<AEnemyShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (!EnemyCharacter)  return EBTNodeResult::Failed;

	EnemyCharacter->UpdatePatrolTargetLocation();

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), EnemyCharacter->GetPatrolTargetLocation());

	return EBTNodeResult::Succeeded;
}
