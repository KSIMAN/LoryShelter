// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "QuestViewerWidget.generated.h"

class UQuestItem;
/**
 * 
 */
UCLASS()
class LORYSHELTER_API UQuestViewerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//--Widget Construct-------------------------------------

	//Native Init
	virtual void NativeOnInitialized() override;
	//Native Construct
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* NameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DescrText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* StepsVerticalBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UQuestTaskWidget> taskViewerClass;

	//Quest Item Reference
	UQuestItem* questRef;

public:
	//--Setters--------------------------------------------

	//Sets Pointer For Quest And Update Info
	void setQuestRef(UQuestItem* questPtr);

	//--Getters---------------------------------------------

	//Returns Pointer On Quest Ref
	UQuestItem* getQuestRef() const { return questRef; };
};
