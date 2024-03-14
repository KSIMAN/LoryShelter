// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedCardWidget.h"
#include "../../Items/Plant.h"
#include "Blueprint/WidgetTree.h"
#include "SeedbedSelectorWidget.h"
#include "SeedbedSelectorWidget.h"


void USeedCardWidget::setSelectorOwner(USeedbedSelectorWidget* owner)
{
	ownerSelector = owner; 
}

USeedCardWidget::USeedCardWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
}

void USeedCardWidget::refreshWidgetInfo()
{
	seedPriceText->SetText(FText::AsNumber(itemInfo.seedPrice));
	seedNameText->SetText(itemInfo.seedName);
	seedDescText->SetText(itemInfo.seedDesc);
}

void USeedCardWidget::onClickPlantSeedButton()
{
	if (!itemInfo.plantClass || !ownerSelector)
		return;

	ownerSelector->OnItemSelected(itemInfo.plantClass);

}

void USeedCardWidget::NativeOnInitialized()
{
	UUserWidget::NativeOnInitialized();
	plantSeedButton->OnClicked.AddDynamic(this, &USeedCardWidget::onClickPlantSeedButton);
	refreshWidgetInfo();
}


void USeedCardWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();
}
