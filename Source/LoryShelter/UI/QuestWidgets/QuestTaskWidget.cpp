// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestTaskWidget.h"
#include "../../Logics/QuestItem.h"

void UQuestTaskWidget::updateStepInfo(FQuestStep stepInfo)
{

	FText stepFormatted = FText::Format(NSLOCTEXT("QuestSpace", "StepInfoText", "{0} {1}/{2}"),
		stepInfo.stepText, stepInfo.doneCounterCurrent, stepInfo.doneCounterMax);

	stepText->SetText(stepFormatted);

	if (stepInfo.bDone)
	{
		//Change TextBlockStyle here
		stepText->SetDefaultColorAndOpacity(FSlateColor(FColor(100, 100, 100, 100)));
	}
}
void UQuestTaskWidget::updateStepInfo(const FText& stepActionText, int doneCounter, int doneMax)
{
	FText stepFormatted = FText::Format(NSLOCTEXT("QuestSpace", "StepInfoText", "{0} {1}/{2}"),
		stepActionText, doneCounter, doneMax);

	stepText->SetText(stepFormatted);

	if (doneCounter >= doneMax)
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


