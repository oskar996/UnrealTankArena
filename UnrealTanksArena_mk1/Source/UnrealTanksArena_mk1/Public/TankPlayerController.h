// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

UCLASS()
class UNREALTANKSARENA_MK1_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	private:
	ATank* GetControlledTank() const;
	void AimingToThePoint();
	bool GetSightRayHitLocation(FVector& HitLocation);

	UPROPERTY(EditAnywhere)
	float CrossXLocation = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrossYLocation = 0.3333f;
};