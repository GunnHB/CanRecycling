// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CanRecyclingPawn.h"
#include "CanRecyclingSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class CANRECYCLING_API ACanRecyclingSportsCar : public ACanRecyclingPawn
{
	GENERATED_BODY()
	
public:

	ACanRecyclingSportsCar();
};
