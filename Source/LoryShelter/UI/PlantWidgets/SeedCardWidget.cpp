// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedCardWidget.h"
#include "../../Items/Plant.h"


USeedCardWidget::USeedCardWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
}
void USeedCardWidget::refreshReference(const FSeedCardInfo& newInfo)
{
	//itemInfo = newInfo;

}

void USeedCardWidget::refreshWidgetInfo()
{
	seedPriceText->SetText(FText::AsNumber(itemInfo.seedPrice));
	seedNameText->SetText(itemInfo.seedName);
}

void USeedCardWidget::onClickPlantSeedButton()
{
	if (!itemInfo.plantClass)
		return;



}

void USeedCardWidget::NativeOnInitialized()
{
	UUserWidget::NativeOnInitialized();
	plantSeedButton->OnClicked.AddDynamic(this, &USeedCardWidget::onClickPlantSeedButton);
	
}


void USeedCardWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();
}
