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

FText UPlantTimerWidget::secondsToLineText(int seconds)
{
	if (seconds == 0)
		return FText::FromStringTable(FName("ItemsST"), TEXT("HARVEST_READY"));

	int minutes = seconds / 60;
	int hours = minutes / 60;

	seconds -= minutes * 60;
	hours -= minutes * 60; //Are you crazy??

	return FText::Format(NSLOCTEXT("QuestSpace", "StepInfoText", " {0}:{1}:{2} "), hours, minutes, seconds);
}
