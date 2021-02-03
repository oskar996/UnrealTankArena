// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurrent.h"

void UTankTurrent::RotatingTheTurrent(float Rotation){
    Rotation = FMath::Clamp<float>(Rotation,-1,1);
    auto RotationChange = MaxRotatingSpeed * Rotation * GetWorld()->DeltaTimeSeconds;
    auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
    SetRelativeRotation(FRotator(0,RawNewRotation,0));
}