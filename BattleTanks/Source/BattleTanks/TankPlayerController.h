// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//Game
#include "Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	//Move the barrel to crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &hitLocation) const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const;

	UPROPERTY(EditAnywhere)
	float m_iCrossHairXlocation = 0.5;
	UPROPERTY(EditAnywhere)
	float m_iCrossHairYlocation = 0.33333;

	float m_fLiineTraceTange = 1000000;
};
