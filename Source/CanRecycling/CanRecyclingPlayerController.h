// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CanRecyclingPlayerController.generated.h"

class UInputMappingContext;
class ACanRecyclingPawn;
class UCanRecyclingUI;

/**
 *  Vehicle Player Controller class
 *  Handles input mapping and user interface
 */
UCLASS(abstract)
class CANRECYCLING_API ACanRecyclingPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	/** Pointer to the controlled vehicle pawn */
	TObjectPtr<ACanRecyclingPawn> VehiclePawn;

	/** Type of the UI to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UCanRecyclingUI> VehicleUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UCanRecyclingUI> VehicleUI;

	// Begin Actor interface
protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:

	virtual void Tick(float Delta) override;

	// End Actor interface

	// Begin PlayerController interface
protected:

	virtual void OnPossess(APawn* InPawn) override;

	// End PlayerController interface
};
