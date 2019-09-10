// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

#include "Engine/World.h"

//Game
#include "TankAimingComponent.h"

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
	float fTime = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank Fired"), fTime);
}

void ATank::AimAt(FVector hitLocaiton)
{
	tanksAimingComponent->AimAt(hitLocaiton, fLaunchSpeed);
}