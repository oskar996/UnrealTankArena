// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
} 

ATank* ATankAIController::GetPlayerTank() const{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay(){
    Super::BeginPlay();
    ATank* Controlled=GetControlledTank();
    
    if(!Controlled){
        UE_LOG(LogTemp,Warning,TEXT("AI controller can't find tank"))
    }
}

void ATankAIController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    
    ATank* Found=GetPlayerTank();
    if(Found){
        AimingToThePoint(Found->GetActorLocation());
    }
}

void ATankAIController::AimingToThePoint(FVector HitPosition){
    ATank* Controlled=GetControlledTank();
    if(Controlled){
        Controlled->AimAt(HitPosition);
    }
}