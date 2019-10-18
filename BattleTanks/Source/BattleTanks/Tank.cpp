// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "Engine/World.h"

//Game
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tanksAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called from BP
void ATank::SetBarrelReferance(UTankBarrel* barrelToSet)
{
	tanksAimingComponent->SetBarrelReferance(barrelToSet);
	barrel = barrelToSet;
}

// Called from BP
void ATank::SetTurretReferance(UTankTurret* turretToSet)
{
	tanksAimingComponent->SetTurretReferance(turretToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - fLastFireTime) > fReloadTimeInSeconds;
	if (barrel && bIsReloaded)
	{
		float fTime = GetWorld()->GetTimeSeconds();
		//Spawn projectile at 
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, barrel->GetSocketLocation("Projectile"), barrel->GetSocketRotation("Projectile"));

		projectile->LaunchProjectile(fLaunchSpeed);
		fLastFireTime = FPlatformTime::Seconds();
	}

}

void ATank::AimAt(FVector hitLocaiton)
{
	tanksAimingComponent->AimAt(hitLocaiton, fLaunchSpeed);
}