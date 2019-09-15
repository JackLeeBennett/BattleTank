// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	FString sName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *sName, throttle);

	//TODO: Clamp these values so player can not drive at different speeds by upping sensativity
}