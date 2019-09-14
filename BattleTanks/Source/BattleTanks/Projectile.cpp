// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

//Game
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement Component"));
	projectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Launching shot at %f"), speed);
	projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector* speed);
	projectileMovement->Activate();
}