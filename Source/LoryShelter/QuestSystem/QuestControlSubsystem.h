// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestControlSubsystem.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EItemNotifyType : uint8
{
	//if item location was changed
	LOCATIONCHANGED,
	//if item was callected 
	ITEMCOLLECTED
};

class AInteractItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractionHappened, AInteractItem*, interactedItem, EItemNotifyType,
                                             notifyType);

UCLASS()
class LORYSHELTER_API UQuestControlSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	//Calls when interaction with item was happened
	//UPROPERTY()
	FInteractionHappened OnInteractionHappened;
};
