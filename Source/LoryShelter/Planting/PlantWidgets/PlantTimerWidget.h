// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlantTimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API UPlantTimerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//sets Planting Item Name
	void setItemName(const FText& newItemName);

	//updates Info about remained time
	void setTimeRemained(int seconds);

	// Called every frame
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:

	//--UI Components--------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemNameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TimeRemainedText;

	//returns line with time in format 00:00:00
	//if seconds == 0 returns "Ready to harvest" 
	FText secondsToLineText(int seconds);
	
};
