// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractor.generated.h"

class IInteractable;

// This class does not need to be modified.
UINTERFACE()
class UInteractor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API IInteractor
{
	GENERATED_BODY()

public:
	//Player is near item and can begin interact if he wants
	virtual void StartFocus(IInteractable* itemPtr) = 0;

	//Player not near item yet. 
	virtual void EndFocus(IInteractable* itemPtr) = 0;

	//Player begin interaction
	virtual void BeginInteract(IInteractable* itemPtr) = 0;

	//Interaction is over
	virtual void EndInteract(IInteractable* itemPtr) = 0;

	//Interaction process
	virtual void Interact(IInteractable* itemPtr) = 0;

	//
	virtual IInteractable* GetFocusItem() = 0;

	//
	virtual void SetFocusItem(IInteractable*) = 0;
};
