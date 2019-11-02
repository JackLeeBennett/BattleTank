// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::RotateTurret(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);

	float fRotationChange = relativeSpeed * m_fMaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float fNewRotation = RelativeRotation.Yaw + fRotationChange;
	
	SetRelativeRotation(FRotator(0, fNewRotation, 0));
}