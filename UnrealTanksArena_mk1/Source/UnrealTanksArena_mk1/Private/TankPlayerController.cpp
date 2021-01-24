// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay(){
    Super::BeginPlay();
    ATank* Controlled = GetControlledTank();
    if(Controlled){
        UE_LOG(LogTemp,Warning,TEXT("Żyje kurla %s"),*(Controlled->GetName()))
    }
    else{
        UE_LOG(LogTemp,Warning,TEXT("Kontroller znowu sie poebal"))
    }
    
}

void ATankPlayerController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    AimingToThePoint();
}

ATank* ATankPlayerController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimingToThePoint(){
    if(!GetControlledTank()){
        UE_LOG(LogTemp,Warning,TEXT("There is a problem with Aiming"))
        return;
    }
    FVector HitLocation;
    if(GetSightRayHitLocation(HitLocation)){
        //UE_LOG(LogTemp,Warning,TEXT("Hit Location: %s"),*(HitLocation.ToString()))
    }

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation){
    
    int32 ViewPortSizeX,ViewPortSizeY;
    GetViewportSize(ViewPortSizeX,ViewPortSizeY);
    FVector2D CrossScreenLocation(ViewPortSizeX*CrossXLocation,ViewPortSizeY*CrossYLocation);
    
    FVector WorldLocation;
    FVector WorldDirection;
    if(DeprojectScreenPositionToWorld(CrossScreenLocation.X, CrossScreenLocation.Y,WorldLocation,WorldDirection)){
        UE_LOG(LogTemp,Warning,TEXT("Aiming Vector: %s"),*(WorldDirection.ToString()))
    }
    
    return true;
}