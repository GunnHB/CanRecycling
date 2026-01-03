// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "CRGoKartBase.generated.h"

class UChaosWheeledVehicleMovementComponent;
struct FInputActionValue;
class UDataAsset_InputConfig;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CANRECYCLING_API ACRGoKartBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACRGoKartBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component|Mesh")
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component|Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component|Camera")
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component|Movement")
	TObjectPtr<UChaosWheeledVehicleMovementComponent> VehicleMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data|Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset = nullptr;

	UFUNCTION(BlueprintImplementableEvent, Category="Vehicle")
	void BrakeLights(bool bBraking);

	
	void Input_Throttle(const FInputActionValue& Value);
	
	void Input_Brake(const FInputActionValue& Value);
	void Input_StartBrake(const FInputActionValue& Value);
	void Input_StopBrake(const FInputActionValue& Value);

	void Input_Steering(const FInputActionValue& Value);
};
