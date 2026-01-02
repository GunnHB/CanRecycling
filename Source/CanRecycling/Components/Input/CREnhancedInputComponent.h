// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "CanRecycling/DataAssets/Input/DataAsset_InputConfig.h"
#include "CREnhancedInputComponent.generated.h"

class UDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class CANRECYCLING_API UCREnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<typename UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template <typename UserObject, typename CallbackFunc>
void UCREnhancedInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null. can not proceed with binding"));

	UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag);
	if (FoundAction != nullptr)
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
}
