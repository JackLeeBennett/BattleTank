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
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *vHitLocation.ToString());
		//Get world location of line trace through the crosshair

		//Tell controlled tank to aim towards hit point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const
{
	//Find the crosshair position in pixel cords (This is not the position in the UMG Widget)
	int32 iViewPortsizeX, iViewPortsizeY;
	GetViewportSize(iViewPortsizeX, iViewPortsizeY);
	FVector2D v2ScreenLocation = FVector2D(m_iCrossHairXlocation * iViewPortsizeX, m_iCrossHairYlocation * iViewPortsizeY);

	FVector vlookDirection;
	if (GetLookDirection(v2ScreenLocation, vlookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *vlookDirection.ToString());
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocaiton, FVector& lookDirection) const
{
	//World location of the crosshair on screen
	FVector vLocation;
	return DeprojectScreenPositionToWorld(screenLocaiton.X, screenLocaiton.Y, vLocation, lookDirection);
}