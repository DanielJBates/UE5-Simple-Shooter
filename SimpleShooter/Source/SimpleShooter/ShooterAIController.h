// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "ShooterAIController.generated.h"

class UBehaviorTree;

UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	AActor* Target;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehaviorTree;

protected:
// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsAlive() const;
};
