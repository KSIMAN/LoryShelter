// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestItem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FQuestStep
{
	GENERATED_USTRUCT_BODY()

	//How much need to do for close Step 
	uint64 doneCounterMax;

	//How much done to do for close Step
	uint64 doneCounterCurrent;

	FText stepText;
};
UCLASS()
class LORYSHELTER_API UQuestItem : public UObject
{
	GENERATED_BODY()
public:
	//Name
	FName questName;

	//Description
	FText questDecr;

	TArray<FQuestStep> questSteps;

};
