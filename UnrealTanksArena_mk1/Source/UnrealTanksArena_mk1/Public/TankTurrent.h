// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTANKSARENA_MK1_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	public:
	void RotatingTheTurrent(float Rotation);

	private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxRotatingSpeed = 20;

};
