// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"

//Game
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* pPlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* pControlledTank = Cast<ATank>(GetPawn());
	if (pPlayerTank && pControlledTank)
	{
		pControlledTank->AimAt(pPlayerTank->GetActorLocation());

		pControlledTank->Fire();
	}

}

//Tut told us not to use these but I think they are a good idea?
//ATank* ATankAIController::GetControlledTank() const
//{
//	return Cast<ATank>(GetPawn());
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
//}