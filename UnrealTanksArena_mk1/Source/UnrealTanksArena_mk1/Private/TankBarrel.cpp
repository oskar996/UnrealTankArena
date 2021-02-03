// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float Elevation){
    
    Elevation = FMath::Clamp<float>(Elevation,-1,1);
    auto ElevationChange = MaxMovingSpeed * Elevation * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    auto FinishElevation = FMath::Clamp<float>(RawNewElevation,MinElevate ,MaxElevate);
    SetRelativeRotation(FRotator(FinishElevation,0,0));
}