// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_ItemConfig.generated.h"

class ACRPickupItem;
/**
 * 
 */
UCLASS()
class CANRECYCLING_API UDataAsset_ItemConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ACRPickupItem> PickupItemClass = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RespawnTime = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bSpawnOnBeginPlay = false;
};
