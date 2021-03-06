// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Projectile.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankTurrent;

UCLASS()
class UNREALTANKSARENA_MK1_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditDefaultsOnly,Category = Setup)
	TSubclassOf<AProjectile> ProjectileClass;
	
	UPROPERTY(EditDefaultsOnly,Category = Firing)
	float ProjectileSpeed = 4000.0;

	UPROPERTY(EditDefaultsOnly,Category = Firing)
	float ReloadTimeInSeconds = 5;

	double LastFireTime = 0;


protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UTankBarrel* Barrel = nullptr;

public:
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelLocation(UTankBarrel* BarrelToSet);
	
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetTurrentLocation(UTankTurrent* TurrentToSet);
	

	void AimAt(FVector Position);

	UFUNCTION(BlueprintCallable,Category = Shoting)
	void Fire();

};
