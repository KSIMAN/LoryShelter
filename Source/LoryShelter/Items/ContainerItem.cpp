// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerItem.h"

AContainerItem::AContainerItem() : AInteractItem(), isEmpty(true)
{
	itemInfo.interactAlias = FString(TEXT("Check Item"));
	itemInfo.interactKey = FString(TEXT("F"));
	itemInfo.itemName = FName(TEXT("Box"));
}
