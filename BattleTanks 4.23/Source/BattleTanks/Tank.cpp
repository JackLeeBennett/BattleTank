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
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - fLastFireTime) > fReloadTimeInSeconds;
	if (m_barrel && bIsReloaded)
	{
		float fTime = GetWorld()->GetTimeSeconds();
		//Spawn projectile at 
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, m_barrel->GetSocketLocation("Projectile"), m_barrel->GetSocketRotation("Projectile"));

		projectile->LaunchProjectile(fLaunchSpeed);
		fLastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector hitLocaiton)
{
	if (!tanksAimingComponent) { return; }

	tanksAimingComponent->AimAt(hitLocaiton, fLaunchSpeed);
}