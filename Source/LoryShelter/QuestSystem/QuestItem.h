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
	FQuestStep() : doneCounterMax(1), doneCounterCurrent(0), QuestObject(nullptr), bDone(false)
	{
	};

	//--Setters-------------------------

	//Current Task Viewer Widget Pointer. Need for UI data update
	void setTaskViewerRef(UQuestTaskWidget* viewerWidget);

	//Increases step progress to 1
	void stepUnitDone();

	//
	void bindQuestObject(UQuestObject* objForImpl);

	UPROPERTY(EditDefaultsOnly)
	//How much need to do for close Step 
	uint64 doneCounterMax;

	UPROPERTY(EditDefaultsOnly)
	//How much done to do for close Step
	uint64 doneCounterCurrent;

	UPROPERTY(EditDefaultsOnly)
	//Quest Step Description
	FText stepText;

	//Class Ref For Quest Object
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UQuestObject> QuestObjectRef;
	
	UPROPERTY(EditDefaultsOnly)
	//Step checker instance
	UQuestObject* QuestObject;

	UPROPERTY(EditDefaultsOnly)
	//Step ready flag
	bool bDone;

	//
	UQuestTaskWidget* viewerPtr; //Im so sorry, Ksush No Forgiveness for you
};

UCLASS()
class LORYSHELTER_API UQuestItem : public UDataAsset
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

	UPROPERTY(EditDefaultsOnly)
	//Name
	FName questName;

	UPROPERTY(EditDefaultsOnly)
	//Description Ты меня разочаровала
	FText questDecr;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FQuestStep> questSteps;
};
