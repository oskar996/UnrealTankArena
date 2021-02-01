// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float ElevateSpeed){
    
    ElevateSpeed = FMath::Clamp<float>(ElevateSpeed,-1,1);
    auto ElevationChange = MaxMovingSpeed * ElevateSpeed * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevate ,MaxElevate);
    SetRelativeRotation(FRotator(Elevation,0,0));
}