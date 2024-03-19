// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "NotifyDispatcher.generated.h"

UENUM(BlueprintType)
enum class EItemNotifyType : uint8
{
	//if item location was changed
	LOCATIONCHANGED,
	//if item was callected 
	ITEMCOLLECTED

};
/**
 * 
 */
class AInteractItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FInteractionHappened, AInteractItem*, interactedItem, EItemNotifyType, notifyType);

UCLASS()
class LORYSHELTER_API UNotifyDispatcher : public UObject
{
	GENERATED_BODY()


	//Singleton instance
	static UNotifyDispatcher* notifyDispatcherInstance;

	//--Defaults -------------------------------------
	UNotifyDispatcher();
	~UNotifyDispatcher();
	UNotifyDispatcher& operator= (UNotifyDispatcher& another) = delete;
	//UNotifyDispatcher& operator= (const UNotifyDispatcher& another) {}; cannot redeclare this by uobject child class. Singleton sucks

public:
	//returns notify dispatcher instance
	static UNotifyDispatcher* getNotifyDispatcherInstance();

	//bind all delegates
	static void bindNotificationDispatchers();

	//Unbinds all delegates
	static void unbindNotificationDispatchers();

	//Calls when interaction with item was happened
	//UPROPERTY()
	FInteractionHappened OnInteractionHappened;


private:
	UFUNCTION()
	void OnInteractionNotify(AInteractItem* item, EItemNotifyType type);
	
};
