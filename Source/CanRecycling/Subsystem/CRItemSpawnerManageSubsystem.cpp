// Fill out your copyright notice in the Description page of Project Settings.


#include "CRItemSpawnerManageSubsystem.h"

UCRItemSpawnerManageSubsystem::UCRItemSpawnerManageSubsystem()
{
}

void UCRItemSpawnerManageSubsystem::RegisterItemSpawner(ACRPickupItemSpawner* InSpawner)
{
	if (ItemSpawners.Contains(InSpawner) == false)
		ItemSpawners.AddUnique(InSpawner);
}
