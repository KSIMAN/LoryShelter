// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestObject.h"
#include "QuestItem.generated.h"

/**
 * 
 */
class UQuestTaskWidget;

USTRUCT(BlueprintType)
struct FQuestStep
{
	GENERATED_USTRUCT_BODY()

	//Default Constructor
	FQuestStep() : bDone(false), doneCounterCurrent(0), doneCounterMax(1), questImpl(nullptr) {};
	
	//--Setters-------------------------

	//Current Task Viewer Widget Pointer. Need for UI data update
	void setTaskViewerRef(UQuestTaskWidget* viewerWidget);

	//Increases step progress to 1
	void stepUnitDone();
	
	//
	void bindQuestObject(UQuestObject* objForImpl);

	//How much need to do for close Step 
	uint64 doneCounterMax;

	//How much done to do for close Step
	uint64 doneCounterCurrent;

	//Quest Step Description
	FText stepText;

	//Step checker instance
	UQuestObject* questImpl;

	//Step ready flag
	bool bDone;
	
	//
	UQuestTaskWidget* viewerPtr; //Im so sorry, Ksush
};
UCLASS()
class LORYSHELTER_API UQuestItem : public UObject
{
	GENERATED_BODY()
public:

	//--Setters----------------------------------------------------------------------------
	
	//Adds Step to quest. actionCounterMax - how much action need be done for quest To end.
	void addQuestStep(const FText& stepDescr, uint64 actionCounterMax = 1, UQuestObject* objForImpl = nullptr);

	
	//--Getters----------------------------------------------------------------------------
	
	//Returns Quest Name
	
	//Returns questDescr
	
	//Returns steps array
	
	//------------------------------------------
	//Name
	FName questName;

	//Description
	FText questDecr;

	TArray<TSharedRef<FQuestStep>> questSteps;

};
