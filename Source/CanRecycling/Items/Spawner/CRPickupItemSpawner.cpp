// Fill out your copyright notice in the Description page of Project Settings.


#include "CRPickupItemSpawner.h"

#include "Components/ArrowComponent.h"


ACRPickupItemSpawner::ACRPickupItemSpawner()
{
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetArrowColor(FColor::Yellow);
	ArrowComponent->SetArrowSize(.3f);
}

void ACRPickupItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	checkf(ItemData, TEXT("Forgot to assign a valid data as item config"));

	// todo: Register spawner with the subsystem
	if (HasAuthority() == false)
		return;
}
