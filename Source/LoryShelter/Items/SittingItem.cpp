// Fill out your copyright notice in the Description page of Project Settings.


#include "SittingItem.h"
#include "../LoryShelterCharacter.h"

ASittingItem::ASittingItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("STOOL"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN"));
	itemInfo.interactDuration = 1;
}


//Remove Code Dubble  with Drag Item Item later
void ASittingItem::Interact(ALoryShelterCharacter* playerPtr)
{
	uint8 interState; //State of interaction 0 - SUCCESS
	if (bItemUsed)
	{
		interState = playerPtr->sitUpFromItem();
		getMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		FVector pointForSeat = findSeatPoint();
		getMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		interState = playerPtr->sitDownToItem(pointForSeat);
	}


	if (interState != 0)
	{
		//Error Message
		return;
	}

	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("SIT_UP")), FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN")));

	//Move to Refocus function

	endFocus(playerPtr);
	beginFocus(playerPtr);
}

FVector ASittingItem::findSeatPoint()
{
	FVector seatPoint;

	seatPoint = getMesh()->GetComponentLocation(); // Replace by linetrace on surface center

	return seatPoint;
}
