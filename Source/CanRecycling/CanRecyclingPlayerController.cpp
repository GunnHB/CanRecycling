// Copyright Epic Games, Inc. All Rights Reserved.


#include "CanRecyclingPlayerController.h"
#include "CanRecyclingPawn.h"
#include "CanRecyclingUI.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosWheeledVehicleMovementComponent.h"

void ACanRecyclingPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// spawn the UI widget and add it to the viewport
	VehicleUI = CreateWidget<UCanRecyclingUI>(this, VehicleUIClass);

	check(VehicleUI);

	VehicleUI->AddToViewport();
}

void ACanRecyclingPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ACanRecyclingPlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	if (IsValid(VehiclePawn) && IsValid(VehicleUI))
	{
		VehicleUI->UpdateSpeed(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed());
		VehicleUI->UpdateGear(VehiclePawn->GetChaosVehicleMovement()->GetCurrentGear());
	}
}

void ACanRecyclingPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// get a pointer to the controlled pawn
	VehiclePawn = CastChecked<ACanRecyclingPawn>(InPawn);
}
