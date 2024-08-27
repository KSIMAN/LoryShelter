// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NotifyDispatcher.h" //Just for notify type :))(())(())
#include "QuestObject.generated.h"

/**
 * 
 */
struct FQuestStep;

UCLASS()
class LORYSHELTER_API UQuestObject : public UObject
{
	GENERATED_BODY()

public:

	//--Setters--------------------------
	void setOwner(FQuestStep* newOwner);

	//-----------------------------------
	//Defeault constructor required by ue
	UQuestObject() {};

	//Constructor for fabric
	UQuestObject( FQuestStep* owner);

	UFUNCTION()
	virtual void OnInteractionNotify(AInteractItem* item, EItemNotifyType type);

protected:
	FQuestStep* owner;
};


class AInteractItem;
class AWorldArea;


//Quest type, when player drag items from some location(A) to point B
UCLASS()
class LORYSHELTER_API UChangeLocationQuestObject : public UQuestObject
{
	GENERATED_BODY()

	//Type of item, that need to be moved. Maybe later i'll make tag-check mechanizm
	TSubclassOf<AInteractItem> itemType;
	
	//Point B area
	AWorldArea* destinationArea;

public:

	virtual ~UChangeLocationQuestObject() {};
	//For Test
	virtual void OnInteractionNotify(AInteractItem* item, EItemNotifyType type);

	//--Setters--------------------------

	//Item Type To Get
	void setItemType(const TSubclassOf<AInteractItem>& newType);

	//
	void setArea(AWorldArea* );
};
