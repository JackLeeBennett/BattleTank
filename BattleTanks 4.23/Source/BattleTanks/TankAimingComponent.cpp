// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

//Game
#include "TankBarrel.h"
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::SetBarrelReferance(UTankBarrel* barrelToSet)
{
	barrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReferance(UTankTurret* turretToSet)
{
	turret = turretToSet;
}

void UTankAimingComponent::AimAt(FVector hitLocation, float launchSpeed)
{
	if (!barrel || !turret) { return; }

	FVector vOutLaunchVelocity(0);
	FVector vStartLocation = barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, vOutLaunchVelocity, vStartLocation, hitLocation, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))	//Need to have all params or this will return false sometimes, its a but in UE
	{
		FVector vAimDirection = vOutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(vAimDirection);
		MoveTurretTowards(vAimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	//Work out difference between curret barrel rotation and aim direction
	FRotator rBarrelRotator = barrel->GetForwardVector().Rotation();
	FRotator rAimAtRotator = aimDirection.Rotation();
	FRotator rDeltaRotator = rAimAtRotator - rBarrelRotator;	//Difference in rotation
	
	barrel->Elevate(rDeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector aimDirection)
{
	//Work out difference between curret turret rotation and aim direction
	FRotator rTurretRotator = turret->GetForwardVector().Rotation();
	FRotator rAimAtRotator = aimDirection.Rotation();
	FRotator rDeltaRotator = rAimAtRotator - rTurretRotator;	//Difference in rotation

	turret->RotateTurret(rDeltaRotator.Yaw);
}