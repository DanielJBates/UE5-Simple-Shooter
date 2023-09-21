// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if(AIBehaviorTree)
    {
        RunBehaviorTree(AIBehaviorTree);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }  
        
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}