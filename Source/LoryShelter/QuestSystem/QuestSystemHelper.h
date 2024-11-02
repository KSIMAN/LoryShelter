// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestControlSubsystem.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QuestSystemHelper.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API UQuestSystemHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Quest System",
		meta = (BlueprintInternalUseOnly = "true", DefaultToSelf = "Outer"))
	static UQuestControlSubsystem* GetQuestControlSubsystem(UWorld* World);
};
