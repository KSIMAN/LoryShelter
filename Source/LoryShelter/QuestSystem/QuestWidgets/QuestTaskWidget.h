// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/RichTextBlock.h"

#include "QuestTaskWidget.generated.h"

/**
 * 
 */
struct FQuestStep;
UCLASS()
class LORYSHELTER_API UQuestTaskWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void updateStepInfo( FQuestStep stepInfo);
	void updateStepInfo(const FText&, int doneCounter, int doneMax);

protected:
	//--Widget Construct-------------------------------------

	//Native Init
	virtual void NativeOnInitialized() override;
	//Native Construct
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	URichTextBlock* stepText;
};
