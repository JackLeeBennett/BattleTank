// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

//Game
#include "Tank.h"

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
		GetControlledTank()->AimAt(vHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const
{
	//Find the crosshair position in pixel cords (This is not the position in the UMG Widget)
	int32 iViewPortsizeX, iViewPortsizeY;
	GetViewportSize(iViewPortsizeX, iViewPortsizeY);
	FVector2D v2ScreenLocation = FVector2D(m_iCrossHairXlocation * iViewPortsizeX, m_iCrossHairYlocation * iViewPortsizeY);

	FVector vLocation;
	FVector vlookDirection;
	if (DeprojectScreenPositionToWorld(v2ScreenLocation.X, v2ScreenLocation.Y, vLocation, vlookDirection))
	{
		GetLookVectorHitLocation(vlookDirection, hitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const
{
	FHitResult hitResult;
	FVector startLocation = PlayerCameraManager->GetCameraLocation();
	FVector endLocation = startLocation + (lookDirection * m_fLiineTraceTange);
	if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility))
	{
		hitLocation = hitResult.Location;
		return true;
	}
	hitLocation = FVector(0);
	return false;
}