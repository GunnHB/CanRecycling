// Copyright Epic Games, Inc. All Rights Reserved.

#include "CanRecyclingWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCanRecyclingWheelFront::UCanRecyclingWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}