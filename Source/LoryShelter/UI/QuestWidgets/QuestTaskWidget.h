// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestTaskWidget.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API UQuestTaskWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	//--Widget Construct-------------------------------------

	//Native Init
	virtual void NativeOnInitialized() override;
	//Native Construct
	virtual void NativeConstruct() override;
};
