// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision")
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max down +1 is max up movement
	void Elevate(float relativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float m_fMaxDegreesPerSecond = 8;

	UPROPERTY(EditAnywhere, Category = Setup)
	float m_fMaxElevation = 35;

	UPROPERTY(EditAnywhere, Category = Setup)
	float m_fMinElevation = 0;
};
