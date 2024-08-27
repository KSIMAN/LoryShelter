// Fill out your copyright notice in the Description page of Project Settings.
#include "DragItem.h"
#include "../LoryShelterCharacter.h"

ADragItem::ADragItem() : AInteractItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("BOX"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("PUT_UP"));
	itemInfo.interactDuration = 1;
	
}

void ADragItem::OnInteract(IInteractor* playerPtr)
{
	uint8 interState = 0; //State of interaction 0 - SUCCESS
	if (bItemUsed)
	{
		//*interState = playerPtr->putDownItem(this);
		getMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		getMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		//*interState = playerPtr->pickUpForDragging(this);
	}
		

	if (interState != 0)
	{
		//Error Message
		return;
	}

	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("PUT_DOWN")), FText::FromStringTable(FName("ActionsST"), TEXT("PUT_UP")));
	
	//Move to Refocus function

	OnEndFocus(playerPtr);
	OnStartFocus(playerPtr);

}

	

