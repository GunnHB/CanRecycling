// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CRItemSpawnerManageSubsystem.generated.h"

class ACRPickupItemSpawner;
/**
 * 
 */
UCLASS()
class CANRECYCLING_API UCRItemSpawnerManageSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UCRItemSpawnerManageSubsystem();

	void RegisterItemSpawner(ACRPickupItemSpawner* InSpawner);

protected:
	UPROPERTY()
	TArray<ACRPickupItemSpawner*> ItemSpawners;
};
