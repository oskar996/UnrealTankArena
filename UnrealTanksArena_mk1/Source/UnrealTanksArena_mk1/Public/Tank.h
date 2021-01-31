// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

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
	
	UPROPERTY(EditAnywhere,Category = Firing)
	float ProjectileVelocity = 100000.0;

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

public:
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelLocation(UTankBarrel* BarrelToSet);
	
	void AimAt(FVector Position);

};
