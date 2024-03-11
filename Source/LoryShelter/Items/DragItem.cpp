// Fill out your copyright notice in the Description page of Project Settings.


#include "DragItem.h"
#include "../LoryShelterCharacter.h"

ADragItem::ADragItem() : AInteractItem(), isRaised(false)
{
	itemInfo.itemName = FName(TEXT("Drag Item"));
	itemInfo.interactAlias = FString(TEXT("Raise"));
	itemInfo.interactDuration = 1;
	
}

void ADragItem::toggleIsRaised()
{
	isRaised = !isRaised;

	if(isRaised)
		itemInfo.interactAlias = FString(TEXT("Put Down"));
	else 
		itemInfo.interactAlias = FString(TEXT("Raise"));
}

void ADragItem::Interact(ALoryShelterCharacter* playerPtr)
{
	uint8 interState; //State of interaction 0 - SUCCESS
	if (isRaised)
	{
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

	

