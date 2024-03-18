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

	//Default Constructor
	FQuestStep() : bDone(false), doneCounterCurrent(0), doneCounterMax(1) {};
	
	//How much need to do for close Step 
	uint64 doneCounterMax;

	//How much done to do for close Step
	uint64 doneCounterCurrent;

	//Quest Step Description
	FText stepText;

	//Step ready flag
	bool bDone;
};
UCLASS()
class LORYSHELTER_API UQuestItem : public UObject
{
	GENERATED_BODY()
public:

	//--Setters----------------------------------------------------------------------------
	
	//Adds Step to quest. actionCounterMax - how much action need be done for quest To end.
	void addQuestStep(const FText& stepDescr, uint64 actionCounterMax = 1);

	//--Getters----------------------------------------------------------------------------
	
	//Returns Quest Name
	
	//Returns questDescr
	
	//Returns steps array
	
	//------------------------------------------
	//Name
	FName questName;

	//Description
	FText questDecr;

	TArray<FQuestStep*> questSteps;

};
