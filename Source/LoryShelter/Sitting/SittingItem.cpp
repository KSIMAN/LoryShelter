// Fill out your copyright notice in the Description page of Project Settings.


#include "SittingItem.h"
#include "Sitter.h"
#include "../LoryShelterCharacter.h"

ASittingItem::ASittingItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("STOOL"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN"));
	itemInfo.interactDuration = 1;
}
//Remove Code Dubble  with Drag Item Item later
void ASittingItem::OnInteract(IInteractor* playerPtr)
{
	ISitter* Sitter = Cast<ISitter>(playerPtr);
	if(!Sitter)return;
	
	uint8 interState = 0; //State of interaction 0 - SUCCESS
	if (bItemUsed)
	{
		interState = Sitter->SitUp(this);
		getMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		getMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		interState = Sitter->SitDown(this);
	}

	if (interState != 0)
	{
		//Error Message
		return;
	}
	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("SIT_UP")), FText::FromStringTable(FName("ActionsST"), TEXT("SIT_DOWN")));
	//Move to Refocus function

	OnEndFocus(playerPtr);
	OnStartFocus(playerPtr);
}

FVector ASittingItem::GetPointToSeat()
{
	return  getMesh()->GetComponentLocation(); // Replace by linetrace on surface center
}
