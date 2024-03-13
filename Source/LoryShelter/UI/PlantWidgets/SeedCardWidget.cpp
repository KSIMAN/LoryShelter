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

}

void USeedCardWidget::NativeOnInitialized()
{
	UUserWidget::NativeOnInitialized();
}


void USeedCardWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();
}
