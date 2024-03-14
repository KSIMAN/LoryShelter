// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedbedSelectorWidget.h"
#include "GameFramework/PlayerController.h"
#include "SeedCardWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../../Items/SeedBedItem.h"


void USeedbedSelectorWidget::refreshSeedCards()
{
	for (auto seedCardClass : itemsToShowClasses)
	{
		USeedCardWidget* seedCard = CreateWidget<USeedCardWidget>(this, seedCardClass.Get());
		if (seedCard)
		{
			seedCard->setSelectorOwner(this);
			seedCardsHolder->AddChildToWrapBox(seedCard);
		}
	}
}

void USeedbedSelectorWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!GetOwningPlayer())
		return;

	GetOwningPlayer()->SetInputMode(FInputModeUIOnly());
	GetOwningPlayer()->bShowMouseCursor = true;
	
	refreshSeedCards();
}

void USeedbedSelectorWidget::BeginDestroy()
{
	Super::BeginDestroy();




}

void USeedbedSelectorWidget::setSeedBedOwner(ASeedBedItem* selectorItem)
{
	ownerItem = selectorItem;
}

void USeedbedSelectorWidget::OnItemSelected(const TSubclassOf<APlant>& selectedPlant)
{
	if (!ownerItem)
		return;

	if (ownerItem->addPlantToSlot(selectedPlant))
	{
		GetOwningPlayer()->SetInputMode(FInputModeGameOnly());
		GetOwningPlayer()->bShowMouseCursor = false;

		RemoveFromParent();

	}
	
}
