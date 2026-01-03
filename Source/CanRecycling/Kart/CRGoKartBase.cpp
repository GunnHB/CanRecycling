// Fill out your copyright notice in the Description page of Project Settings.


#include "CRGoKartBase.h"

#include "ChaosWheeledVehicleMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "CanRecycling/CRGameplayTags.h"
#include "CanRecycling/Components/Input/CREnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "CanRecycling/DataAssets/Input/DataAsset_InputConfig.h"

// Sets default values
ACRGoKartBase::ACRGoKartBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetReplicates(true);
	
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SetRootComponent(SkeletalMeshComponent);
	SkeletalMeshComponent->SetSimulatePhysics(true);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(SkeletalMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	VehicleMovementComponent = CreateDefaultSubobject<UChaosWheeledVehicleMovementComponent>(TEXT("VehicleMovementComponent"));
}

// Called when the game starts or when spawned
void ACRGoKartBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACRGoKartBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACRGoKartBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data as input config"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UCREnhancedInputComponent* CRInputComponent = CastChecked<UCREnhancedInputComponent>(PlayerInputComponent);
	
	CRInputComponent->BindNativeInputAction(InputConfigDataAsset, CRGameplayTag::InputTag_Throttle, ETriggerEvent::Triggered, this, &ACRGoKartBase::Input_Throttle);
	CRInputComponent->BindNativeInputAction(InputConfigDataAsset, CRGameplayTag::InputTag_Throttle, ETriggerEvent::Completed, this, &ACRGoKartBase::Input_Throttle);

	CRInputComponent->BindNativeInputAction(InputConfigDataAsset, CRGameplayTag::InputTag_Brake, ETriggerEvent::Triggered, this, &ACRGoKartBase::Input_Brake);
}

void ACRGoKartBase::Input_Throttle(const FInputActionValue& Value)
{
	const float Throttle = Value.Get<float>();

	VehicleMovementComponent->SetThrottleInput(Throttle);
}

void ACRGoKartBase::Input_Brake(const FInputActionValue& Value)
{
	const float Brake = Value.Get<float>();

	VehicleMovementComponent->SetBrakeInput(Brake);
}
