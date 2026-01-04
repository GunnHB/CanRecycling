// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRPickupItem.generated.h"

class USphereComponent;
class UNiagaraComponent;

UCLASS()
class CANRECYCLING_API ACRPickupItem : public AActor
{
	GENERATED_BODY()

public:
	ACRPickupItem();

	virtual void BeginPlay() override;

	void SetActive(const bool bActive);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components|Core")
	TObjectPtr<USphereComponent> SphereComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components|Niagara")
	TObjectPtr<UNiagaraComponent> NiagaraComponent = nullptr;

private:
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
