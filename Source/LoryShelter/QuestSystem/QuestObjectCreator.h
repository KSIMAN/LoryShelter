// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UQuestSystemComponent;

class LORYSHELTER_API QuestObjectCreator
{
public:
	QuestObjectCreator();
	~QuestObjectCreator();

	static void initFlourSucksQuest(UQuestSystemComponent* compPtr);

	//--Helpers----------------------------------------------------
	static UClass* findBPClassReference(const FString& classPath);
};
