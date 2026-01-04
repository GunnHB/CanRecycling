// Fill out your copyright notice in the Description page of Project Settings.


#include "CRPickupItem.h"

#include "CanRecycling/DebugHelper.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"

ACRPickupItem::ACRPickupItem()
{
	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
	NiagaraComponent->SetupAttachment(SphereComponent);
}

void ACRPickupItem::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACRPickupItem::OnComponentBeginOverlap);
}

void ACRPickupItem::SetActive(const bool bActive)
{
	SetActorHiddenInGame(!bActive);
	SetActorEnableCollision(bActive);
}

void ACRPickupItem::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Debug::Print(TEXT("Overlap"));
}
