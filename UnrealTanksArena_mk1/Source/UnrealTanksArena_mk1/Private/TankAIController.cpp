// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay(){
    Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    
    ATank* Found = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    ATank* Controlled = Cast<ATank>(GetPawn());
    if(Found && Controlled){
        Controlled -> AimAt(Found->GetActorLocation());
        Controlled -> Fire();
    }
    else{
        UE_LOG(LogTemp,Error,TEXT("Problem with AI Controller"))
    }
}
