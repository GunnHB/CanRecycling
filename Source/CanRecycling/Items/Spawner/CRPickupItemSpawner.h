// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRPickupItemSpawner.generated.h"

class ACRPickupItem;
class UDataAsset_ItemConfig;
class UArrowComponent;

UCLASS()
class CANRECYCLING_API ACRPickupItemSpawner : public AActor
{
	GENERATED_BODY()

public:
	ACRPickupItemSpawner();

	virtual void BeginPlay() override;

protected:
	void SpawnItem();
	void RespawnItem();

	UFUNCTION()
	void StartRespawnTimer();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components|Core")
	TObjectPtr<UArrowComponent> ArrowComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UDataAsset_ItemConfig> ItemData = nullptr;

	UPROPERTY()
	TObjectPtr<ACRPickupItem> SpawnedItem = nullptr;
	
	FTimerHandle RespawnTimer;
};
