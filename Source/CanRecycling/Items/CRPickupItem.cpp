// Fill out your copyright notice in the Description page of Project Settings.


#include "CRPickupItem.h"

#include "CanRecycling/DebugHelper.h"
#include "Components/SphereComponent.h"

ACRPickupItem::ACRPickupItem()
{
	SetReplicates(true);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(SphereComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACRPickupItem::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ACRPickupItem::OnComponentBeginOverlap);
}

void ACRPickupItem::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Debug::Print(TEXT("Overlap"));
}
