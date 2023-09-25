// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AKillThemAllGameMode::PawnKilled(APawn* Pawn)
{
    Super::PawnKilled(Pawn);

    if(APlayerController* PlayerController = Cast<APlayerController>(Pawn->GetController()))
    {
        EndGame(false);
    }
    
    for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if(Controller->IsAlive())
        {
            return;
        }
    }
    
    EndGame(true);
}

void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}