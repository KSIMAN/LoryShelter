// Fill out your copyright notice in the Description page of Project Settings.


#include "SittingItem.h"
#include "../LoryShelterCharacter.h"

ASittingItem::ASittingItem() : isBusy(false)
{
	itemInfo.itemName = FName(TEXT("Sitting Item"));
	itemInfo.interactAlias = FString(TEXT("Sit Down"));
	itemInfo.interactDuration = 1;
}

//Remove Code Dubble  with Drag Item later
void ASittingItem::toggleIsBusy()
{
	
	isBusy = !isBusy;

	if (isBusy)
		itemInfo.interactAlias = FString(TEXT("Get Up"));
	else
		itemInfo.interactAlias = FString(TEXT("Sit Down"));
}

//Remove Code Dubble  with Drag Item Item later
void ASittingItem::Interact(ALoryShelterCharacter* playerPtr)
{
	uint8 interState; //State of interaction 0 - SUCCESS
	if (isBusy)
	{
		if(playerPtr->GetMesh()->)
		interState = playerPtr->putDownItem(this);
		getMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		getMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		interState = playerPtr->pickUpForDragging(this);
	}


	if (interState != 0)
	{
		//Error Message
		return;
	}

	toggleIsRaised();

	//Move to Refocus function

	endFocus(playerPtr);
	beginFocus(playerPtr);
}

FVector ASittingItem::findSeatPoint()
{
	return FVector();
}
