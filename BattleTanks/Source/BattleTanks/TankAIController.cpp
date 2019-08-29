// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"

//Game
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();
	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing: %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not possesing tank!"));
	}

	ATank* playerTank = GetPlayerTank();

	if (playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found the player controller: %s"), *playerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller did not find the player controller!"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* pPedTank = GetPlayerTank();
	if (pPedTank)
	{
		GetControlledTank()->AimAt(pPedTank->GetActorLocation());
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}