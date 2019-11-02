// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetBarrelReferance(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTurretReferance(UTankTurret* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

	void AimAt(FVector hitLocation);

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* tanksAimingComponent = nullptr;

private:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float fReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float fLaunchSpeed = 10000; // TODO: Find sensible default


	//Barrel ref for spawning projectiles
	UTankBarrel* barrel = nullptr;


	double fLastFireTime = 0;
};
