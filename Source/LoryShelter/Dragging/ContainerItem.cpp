// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainerItem.h"

AContainerItem::AContainerItem() : isEmpty(true)
{
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("CHECK"));
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("BOX"));
}

void AContainerItem::BeginPlay()
{
	Super::BeginPlay();
}
