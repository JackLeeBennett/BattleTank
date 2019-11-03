// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float throttle);

private:
	//This is the max force per track in newtons
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
		float fTrackMaxDrivingForce = 200000000.f;	//Assume 40 tonne tank, and 1g acceleration
};
