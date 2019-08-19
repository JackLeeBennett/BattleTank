// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();
	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayController not possesing tank!"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if(!GetControlledTank()) { return; }

	FVector vHitLocation; 
	if (GetSightRayHitLocation(vHitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *vHitLocation.ToString());
		//Get world location of line trace through the crosshair

		//Tell controlled tank to aim towards hit point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const
{
	hitLocation = FVector(1.0);
	return false;
}