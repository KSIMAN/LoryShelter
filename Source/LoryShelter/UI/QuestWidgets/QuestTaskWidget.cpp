// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTaskWidget.h"
#include "../../Logics/QuestItem.h"

void UQuestTaskWidget::updateStepInfo(FQuestStep* stepInfo)
{
	if (!stepInfo)
		return;
	FString stepInfoStr = stepInfo->stepText.ToString() + FString("  ") +  FString::FormatAsNumber(stepInfo->doneCounterCurrent) + FString("/") + FString::FormatAsNumber(stepInfo->doneCounterMax);

	stepText->SetText(FText::FromString(stepInfoStr));

	if (stepInfo->bDone)
	{
		//Change TextBlockStyle here
		stepText->SetDefaultColorAndOpacity(FSlateColor(FColor(100, 100, 100, 100)));
	}
}
void UQuestTaskWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UQuestTaskWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


