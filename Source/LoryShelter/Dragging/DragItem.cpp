// Fill out your copyright notice in the Description page of Project Settings.
#include "DragItem.h"
#include "Dragger.h"
#include "../QuestSystem/NotifyDispatcher.h"
#include "../LoryShelterCharacter.h"

ADragItem::ADragItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("BOX"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("PUT_UP"));
	itemInfo.interactDuration = 1;
	
}

void ADragItem::OnInteract(IInteractor* Interactor)
{
	IDragger* Dragger = Cast<IDragger>(Interactor);
	if(!Dragger)
		return;
	uint8 interState = 0; //State of interaction 0 - SUCCESS
	if (bItemUsed)
	{
		interState = Dragger->PutDown(this);
	}
	else
	{
		interState = Dragger->PutUp(this);
	}
	if (interState != 0)
	{
		//Error Message
		return;
	}
	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("PUT_DOWN")), FText::FromStringTable(FName("ActionsST"), TEXT("PUT_UP")));
	//Move to Refocus function
	OnEndFocus(Interactor);
	OnStartFocus(Interactor);

}

void ADragItem::OnPutUp(IDragger* Dragger)
{
	getMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FDragInfo DragInfo = Dragger->GetDragInfo();
	SetActorLocation(DragInfo.AttachmentPoint);
	SetActorRotation(DragInfo.AttachmentRotator);
	if(DragInfo.bToSocket)
		AttachToComponent(DragInfo.AttachmentActor->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, DragInfo.SocketName);
	// else
	// 	AttachToActor(DragInfo.AttachmentActor);
}

void ADragItem::OnPutDown(IDragger* Dragger)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	SetActorLocation(Dragger->GetPutDownPoint());
	SetActorRotation(FRotator::ZeroRotator);
	getMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	UNotifyDispatcher::getNotifyDispatcherInstance()->OnInteractionHappened.Broadcast(Cast<AInteractItem>(this), EItemNotifyType::LOCATIONCHANGED);
}

	

