// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector Position){
	TankAimingComponent->AimAt(Position,ProjectileSpeed);
}

void ATank::SetBarrelLocation(UTankBarrel* BarrelToSet){
	TankAimingComponent->SetBarrelLocation(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurrentLocation(UTankTurrent* TurrentToSet){
	TankAimingComponent->SetTurrentLocation(TurrentToSet);
}

void ATank::Fire(){
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp,Warning,TEXT("%f Strzal"),Time)	

	if(!Barrel){
		UE_LOG(LogTemp,Warning,TEXT("No Barrel Reference in Tank class %f"),*GetName())
		return;
	}

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass,Barrel->GetSocketLocation(FName("Projectile")),Barrel->GetSocketRotation(FName("Projectile")));
	Projectile->LaunchProjectile(ProjectileSpeed);
}
