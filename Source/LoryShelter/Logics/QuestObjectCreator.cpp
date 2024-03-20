// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestObjectCreator.h"
#include "QuestItem.h"
#include "Kismet/GameplayStatics.h"
#include "QuestObject.h"
#include "../Primitives/WorldArea.h"
#include "../Logics/QuestSystemComponent.h"

QuestObjectCreator::QuestObjectCreator()
{
}

QuestObjectCreator::~QuestObjectCreator()
{
}

void QuestObjectCreator::initFlourSucksQuest(UQuestSystemComponent* compPtr)
{
	UQuestItem* quest = NewObject<UQuestItem>(compPtr);

	quest->questName = FName("Barn work");
	quest->questDecr = FText(FText::FromString(TEXT("Load sacks of flour form the barn into the truck at the entrance")));

	UChangeLocationQuestObject* questObj = NewObject<UChangeLocationQuestObject>(quest);
	if (questObj)
	{
		//UGameplayStatics::GetAllActorsOfClassWithTag() future

		UClass* sackref = QuestObjectCreator::findBPClassReference(TEXT("/Game/Blueprints/Items/SackItemBP.SackItemBP_C"));
		AActor* areaActor = UGameplayStatics::GetActorOfClass(compPtr->GetWorld(), AWorldArea::StaticClass());
		//area to check location
		questObj->setArea(Cast<AWorldArea>(areaActor));
		//Type of item to check location
		questObj->setItemType(sackref);
		//addQuestStep
		quest->addQuestStep(FText::FromString(TEXT("Sacks loaded ")), 10, questObj);
	}
	compPtr->addQuest(quest);
}

UClass* QuestObjectCreator::findBPClassReference(const FString& classPath)
{
	FSoftClassPath ItemClassRef(classPath);
	return ItemClassRef.TryLoadClass<AActor>();
}
