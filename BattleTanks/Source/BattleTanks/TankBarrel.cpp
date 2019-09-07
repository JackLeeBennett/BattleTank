// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float relativeSpeed)
{
	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0f, 1.0f);

	float fElevationChange = relativeSpeed * m_fMaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float fRawNewElevation = RelativeRotation.Pitch + fElevationChange;
	float fElevation = FMath::Clamp<float>(fRawNewElevation, m_fMinElevation, m_fMaxElevation);

	SetRelativeRotation(FRotator(fElevation, 0, 0));
}