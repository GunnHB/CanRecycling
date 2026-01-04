// Fill out your copyright notice in the Description page of Project Settings.


#include "CRPickupItemSpawner.h"

#include "CanRecycling/DataAssets/Item/DataAsset_ItemConfig.h"
#include "CanRecycling/Items/CRPickupItem.h"
#include "CanRecycling/Subsystem/CRItemSpawnerManageSubsystem.h"
#include "Components/ArrowComponent.h"


ACRPickupItemSpawner::ACRPickupItemSpawner()
{
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetArrowColor(FColor::Yellow);
	ArrowComponent->SetArrowSize(.3f);
	SetRootComponent(ArrowComponent);
}

void ACRPickupItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	checkf(ItemData, TEXT("Forgot to assign a valid data as item config"));

	// Register spawner with the subsystem
	if (HasAuthority() == false)
		return;

	UCRItemSpawnerManageSubsystem* Manager = GetWorld()->GetSubsystem<UCRItemSpawnerManageSubsystem>();
	if (IsValid(Manager))
		Manager->RegisterItemSpawner(this);

	if (ItemData->bSpawnOnBeginPlay)
		SpawnItem();
}

void ACRPickupItemSpawner::SpawnItem()
{
	FActorSpawnParameters SpawnParams;
	
	SpawnedItem = GetWorld()->SpawnActor<ACRPickupItem>(ItemData->PickupItemClass, GetActorLocation(), GetActorRotation(), SpawnParams);
	// if (IsValid(SpawnedItem))
	// 	SpawnedItem->SetActive(false);
}
