// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestViewerWidget.h"
#include "../../Logics/QuestItem.h"

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
	
	if (!questRef) return;

	NameText->SetText(FText::FromName(questRef->questName));
	DescrText->SetText(questRef->questDecr);
	
	for (auto step : questRef->questSteps)
	{
		//Create Step Widget Here
	}
}
