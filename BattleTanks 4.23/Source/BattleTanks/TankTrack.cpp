// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle)
{
	FString sName = GetName();

	FVector vForceApplied = GetForwardVector() * throttle * fTrackMaxDrivingForce;
	FVector	vForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(vForceApplied, vForceLocation);

	UE_LOG(LogTemp, Warning, TEXT("Adding throttle %f to track: %s"), throttle, *TankRoot->GetName());
}