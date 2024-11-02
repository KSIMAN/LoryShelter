// Fill out your copyright notice in the Description page of Project Settings.
#include "QuestPanel.h"
#include "QuestViewerWidget.h"


void UQuestPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UQuestPanel::NativeConstruct()
{
	Super::NativeConstruct();
}

void UQuestPanel::refreshPanelInfo(const TArray<UQuestItem*>& quests)
{
	if (!questViewerClass)
	{
		return; //Add Debug Error Message Later
	}

	for (auto quest : quests)
	{
		UQuestViewerWidget* questView = CreateWidget<UQuestViewerWidget>(this, questViewerClass);
		questView->setQuestRef(quest);
		questView->SetVisibility(ESlateVisibility::Visible);
		QuestsViewerBox->AddChild(questView);
	}
}
