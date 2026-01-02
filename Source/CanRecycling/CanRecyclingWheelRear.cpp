// Copyright Epic Games, Inc. All Rights Reserved.

#include "CanRecyclingWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCanRecyclingWheelRear::UCanRecyclingWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}