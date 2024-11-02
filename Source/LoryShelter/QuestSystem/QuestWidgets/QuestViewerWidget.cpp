// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestViewerWidget.h"
#include "QuestTaskWidget.h"
#include "../QuestItem.h"

void UQuestViewerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UQuestViewerWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UQuestViewerWidget::setQuestRef(UQuestItem* questPtr)
{
	questRef = questPtr;

	if (!questRef)
	{
		return;
	}

	NameText->SetText(FText::FromName(questRef->questName));
	DescrText->SetText(questRef->questDecr);

	if (StepsVerticalBox->GetChildrenCount())
	{
		StepsVerticalBox->ClearChildren();
	}

	if (!taskViewerClass)
	{
		return;
	}

	for (auto step : questRef->questSteps)
	{
		UQuestTaskWidget* taskView = CreateWidget<UQuestTaskWidget>(GetWorld(), taskViewerClass.Get());
		if (taskView)
		{
			step.Get().setTaskViewerRef(taskView);
			taskView->updateStepInfo(step.Get());
			StepsVerticalBox->AddChild(taskView);
		}

		//Create Step Widget Here
	}
}
