// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	FString sName = GetName();

	//TODO: Clamp these values so player can not drive at different speeds by upping sensativity
	FVector vForceApplied = GetForwardVector() * throttle * fTrackMaxDrivingForce;
	FVector	vForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(vForceApplied, vForceLocation);
}