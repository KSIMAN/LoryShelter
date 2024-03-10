// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystemComponent.h"
#include "../LoryShelterCharacter.h"
#include "../UI/QuestWidgets/QuestPanel.h"

// Sets default values for this component's properties
UQuestSystemComponent::UQuestSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// ...
}

void UQuestSystemComponent::initQuestPanel()
{
	if (questPanelClass)
	{
		questPanel = CreateWidget<UQuestPanel>(GetWorld(), questPanelClass);
		questPanel->AddToViewport(999);
		questPanel->SetVisibility(ESlateVisibility::Visible);
	}
}

void UQuestSystemComponent::addQuest(UQuestItem* questItem)
{
	if (!questItem)
		return;

	quests.Add(questItem);
	questPanel->refreshPanelInfo(quests);
}


// Called when the game starts
void UQuestSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	initQuestPanel();

}


// Called every frame
void UQuestSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

