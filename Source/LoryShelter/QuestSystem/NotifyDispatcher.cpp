// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyDispatcher.h"
#include "../Interactions/InteractItem.h"



UNotifyDispatcher* UNotifyDispatcher::notifyDispatcherInstance = nullptr;

UNotifyDispatcher::UNotifyDispatcher()
{
	notifyDispatcherInstance = this;
//	bindNotificationDispatchers();
}
UNotifyDispatcher::~UNotifyDispatcher()
{
	notifyDispatcherInstance = nullptr;
//	unbindNotificationDispatchers();
}

UNotifyDispatcher* UNotifyDispatcher::getNotifyDispatcherInstance()
{
	return UNotifyDispatcher::notifyDispatcherInstance;
	
}

void UNotifyDispatcher::bindNotificationDispatchers()
{
	UNotifyDispatcher* dispInstance = getNotifyDispatcherInstance();

	dispInstance->OnInteractionHappened.AddUniqueDynamic(dispInstance, &UNotifyDispatcher::OnInteractionNotify);
}

void UNotifyDispatcher::unbindNotificationDispatchers()
{
	UNotifyDispatcher* dispInstance = getNotifyDispatcherInstance();
	dispInstance->OnInteractionHappened.RemoveDynamic(dispInstance, &UNotifyDispatcher::OnInteractionNotify);
}

void UNotifyDispatcher::OnInteractionNotify(AInteractItem* item, EItemNotifyType type)
{
	UE_LOG(LogTemp, Log, TEXT("Interaction Notification"));
}
