// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "QuestPanel.generated.h"

/**
 * 
 */
class UQuestItem;
class UQuestViewerWidget;

UCLASS()
class LORYSHELTER_API UQuestPanel : public UUserWidget
{
	GENERATED_BODY()
	
public:


	//Refreshes quests info by quest array
	void refreshPanelInfo(const TArray<UQuestItem*>& quests);

protected:
	//--Widget Construct-------------------------------------

	//Native Init
	virtual void NativeOnInitialized() override;
	//Native Construct
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* QuestsViewerBox;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UQuestViewerWidget> questViewerClass;


};
