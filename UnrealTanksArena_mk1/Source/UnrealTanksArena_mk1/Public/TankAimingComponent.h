// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankTurrent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTANKSARENA_MK1_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector AimPosition,float VelocityOfProjectile);
	void SetBarrelLocation(UTankBarrel* BarrelToSet);			//TO DO:Change Names of the functions
	void SetTurrentLocation(UTankTurrent* TurrentToSet);
	void MoveBarrel(FVector AimVelocityVector);
	void MoveTurrent(FVector AimVelocityVector);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;
};
