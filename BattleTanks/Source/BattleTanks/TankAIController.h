// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//Game
#include "Tank.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank();

	void BeginPlay() override;
	
};
