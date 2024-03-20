// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestObject.h"
#include "../Items/InteractItem.h"
#include "QuestItem.h"
#include "../Primitives/WorldArea.h"


void UQuestObject::setOwner(FQuestStep* newOwner)
{
	owner = newOwner;
}

UQuestObject::UQuestObject(FQuestStep* owner) : UObject()
{

}

void UQuestObject::OnInteractionNotify(AInteractItem* item, EItemNotifyType type)
{
	UE_LOG(LogTemp, Log, TEXT("Interaction Notification"));
}

//--Change Location Quest----------------------------------------------------------------------

void UChangeLocationQuestObject::OnInteractionNotify(AInteractItem* item, EItemNotifyType type)
{
	if (!item || !destinationArea)
		return;

	if ((item->GetClass()->IsChildOf(itemType.Get()) || item->GetClass() == itemType.Get()) && type == EItemNotifyType::LOCATIONCHANGED) //Notification for correct item
	{
		if (destinationArea->checkActorInArea(item)) //Step unit done!!
		{
			owner->stepUnitDone();
		}
	}
	
}

void UChangeLocationQuestObject::setItemType(const TSubclassOf<AInteractItem>& newType)
{
	itemType = newType;
}

void UChangeLocationQuestObject::setArea(AWorldArea* newArea)
{
	destinationArea = newArea;
}
