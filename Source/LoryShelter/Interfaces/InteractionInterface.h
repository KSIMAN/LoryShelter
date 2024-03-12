// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

// This class does not need to be modified.
class ALoryShelterCharacter;

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
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

class LORYSHELTER_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
protected:

	//Indicates that player used this item. Uses for toggle-type interaction
	bool bItemUsed;

	//Toggle type interaction handler
	virtual void ToggleItemUsed(const FText& itemUsedAlias, const FText& itemNotUsedAlias);

	FInteractionInfo itemInfo;

public:

	//Player is near item and can begin interact if he wants
	virtual void beginFocus(ALoryShelterCharacter* playerPtr);

	//Player not near item yet. 
	virtual void endFocus(ALoryShelterCharacter* playerPtr);

	//Player begin interaction
	virtual void beginInteract(ALoryShelterCharacter* playerPtr);

	//Interaction is over
	virtual void endInteract(ALoryShelterCharacter* playerPtr);

	//Interaction process
	virtual void Interact(ALoryShelterCharacter* playerPtr);

};
