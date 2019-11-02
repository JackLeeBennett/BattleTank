// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:
	//Move the barrel to crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &hitLocation) const;
	bool GetLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float m_iCrossHairXlocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float m_iCrossHairYlocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float m_fLiineTraceTange = 1000000;
};
