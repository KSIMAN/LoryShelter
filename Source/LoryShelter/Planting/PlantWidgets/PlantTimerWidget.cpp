// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantTimerWidget.h"

void UPlantTimerWidget::setItemName(const FText& newItemName)
{
	ItemNameText->SetText(newItemName);
}

void UPlantTimerWidget::setTimeRemained(int seconds)
{
	TimeRemainedText->SetText(secondsToLineText(seconds));
}

void UPlantTimerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

FText UPlantTimerWidget::secondsToLineText(int seconds)
{
	if (seconds == 0)
	{
		return FText::FromStringTable(FName("ItemsST"), TEXT("HARVEST_READY"));
	}

	int hours = seconds / 3600;
	int minutes = seconds / 60;
	seconds = seconds % 60;
	return FText::Format(NSLOCTEXT("QuestSpace", "StepInfoText", " {0}:{1}:{2} "), hours, minutes, seconds);
}
