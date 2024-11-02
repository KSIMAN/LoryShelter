// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

// This class does not need to be modified.

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInteractionInfo
{
	GENERATED_USTRUCT_BODY()

	//Item name
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText itemName;

	//Alias to show before interacting
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText interactAlias;

	//Key For Interaction. Maybe Deprecated
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText interactKey;

	//Duration of interaction in seconds
	int interactDuration;
};

class IInteractor;
DECLARE_MULTICAST_DELEGATE_OneParam(FOnFocusStarted, IInteractor)

class LORYSHELTER_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:
	//Player is near item and can begin interact if he wants
	virtual void OnStartFocus(IInteractor* playerPtr);

	//Player not near item yet. 
	virtual void OnEndFocus(IInteractor* playerPtr);

	//Player begin interaction
	virtual void OnBeginInteract(IInteractor* playerPtr);

	//Interaction is over
	virtual void OnEndInteract(IInteractor* playerPtr);

	//Interaction process
	virtual void OnInteract(IInteractor* playerPtr);
	//
	virtual UAnimMontage* GetInteractAnimation() = 0;
	//
	virtual const FInteractionInfo& GetInteractionInfo() = 0;
};
