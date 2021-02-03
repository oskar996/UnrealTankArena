// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankAimingComponent::AimAt(FVector AimPosition, float VelocityOfProjectile){
	if(!Barrel){
		return;
	}

	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector AimVelocityVector;
	
	if(UGameplayStatics::SuggestProjectileVelocity(this,AimVelocityVector,StartLocation,AimPosition,VelocityOfProjectile,false,0,0,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		MoveBarrel(AimVelocityVector.GetSafeNormal());
		MoveTurrent(AimVelocityVector.GetSafeNormal());
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp,Warning,TEXT("%f Dziala %s"),Time,*AimPosition.ToString())	
	}
}

void UTankAimingComponent::SetBarrelLocation(UTankBarrel* BarrelToSet){
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurrentLocation(UTankTurrent* TurrentToSet){
	Turrent = TurrentToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimVelocityVector){
	FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimVelocityVector.Rotation();
	FRotator Delta = AimRotation - BarrelRotation;
	Barrel->Elevate(Delta.Pitch);
}

void UTankAimingComponent::MoveTurrent(FVector AimVelocityVector){
	FRotator TurrentRotation = Turrent->GetForwardVector().Rotation();
	FRotator AimRotation = AimVelocityVector.Rotation();
	FRotator Delta = AimRotation - TurrentRotation;
	Turrent->RotatingTheTurrent(Delta.Yaw);
}