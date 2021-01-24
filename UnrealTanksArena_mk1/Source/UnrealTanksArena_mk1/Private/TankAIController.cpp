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
    ATank* Found=GetPlayerTank();
    if(Controlled){
        UE_LOG(LogTemp,Warning,TEXT("AI zyje kurla: %s"),*(Controlled->GetName()))
    }
    else{
        UE_LOG(LogTemp,Warning,TEXT("AI sie poebao"))
    }
    
    if(Found){
        UE_LOG(LogTemp,Warning,TEXT("AI widzi cie: %s"),*(Found->GetName()))
    }
    else{
        UE_LOG(LogTemp,Warning,TEXT("AI osleplo"))
    }
}