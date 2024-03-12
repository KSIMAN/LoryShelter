// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionInterface.h"

// Add default functionality here for any IInteractionInterface functions that are not pure virtual.

void IInteractionInterface::ToggleItemUsed(const FText& itemUsedAlias, const FText& itemNotUsedAlias)
{
	bItemUsed = !bItemUsed;
	if (bItemUsed)
		itemInfo.interactAlias = itemUsedAlias;
	else
		itemInfo.interactAlias = itemNotUsedAlias;
}

void IInteractionInterface::beginFocus(ALoryShelterCharacter* playerPtr)
{
	//When player is near
}

void IInteractionInterface::endFocus(ALoryShelterCharacter* playerPtr)
{
	//When player not near yet
}

void IInteractionInterface::beginInteract(ALoryShelterCharacter* playerPtr)
{
	//SetTimer Here
}

void IInteractionInterface::endInteract(ALoryShelterCharacter* playerPtr)
{
	//Call when Timer Elapsed
}

void IInteractionInterface::Interact(ALoryShelterCharacter* playerPtr)
{
}
