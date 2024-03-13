// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedbedSelectorWidget.h"
#include "../../Items/SeedBedItem.h"


void USeedbedSelectorWidget::setSeedBedOwner(ASeedBedItem* selectorItem)
{
	ownerItem = selectorItem;
}

void USeedbedSelectorWidget::OnItemSelected(const TSubclassOf<APlant>& selectedPlant)
{
	if (!ownerItem)
		return;

	ownerItem->addPlantToSlot(selectedPlant);
}
