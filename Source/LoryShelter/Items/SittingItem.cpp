// Fill out your copyright notice in the Description page of Project Settings.


#include "SittingItem.h"
#include "../LoryShelterCharacter.h"

ASittingItem::ASittingItem() : isBusy(false)
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("STOOL"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN"));
	itemInfo.interactDuration = 1;
}

//Remove Code Dubble  with Drag Item later
void ASittingItem::toggleIsBusy()
{
	
	isBusy = !isBusy;

	if (isBusy)
		itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("SIT_UP"));
	else
		itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN"));
}

//Remove Code Dubble  with Drag Item Item later
void ASittingItem::Interact(ALoryShelterCharacter* playerPtr)
{
	uint8 interState; //State of interaction 0 - SUCCESS
	if (isBusy)
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

	toggleIsBusy();

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
