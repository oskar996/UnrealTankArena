// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTANKSARENA_MK1_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	public:
	void Elevate(float Elevation);

	private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxMovingSpeed = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevate = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevate = 0;
};
