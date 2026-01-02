// Copyright Epic Games, Inc. All Rights Reserved.

#include "CanRecyclingGameMode.h"
#include "CanRecyclingPlayerController.h"

ACanRecyclingGameMode::ACanRecyclingGameMode()
{
	PlayerControllerClass = ACanRecyclingPlayerController::StaticClass();
}
