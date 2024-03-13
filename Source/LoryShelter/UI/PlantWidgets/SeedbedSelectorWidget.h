// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SeedbedSelectorWidget.generated.h"

/**
 * 
 */
class USeedCardWidget;
class ASeedBedItem;
class APlant;


UCLASS()
class LORYSHELTER_API USeedbedSelectorWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	//Seedcards that will be shown 
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	TArray<USeedCardWidget*> itemsToShow;

	//Ownet item Ptr
	ASeedBedItem* ownerItem;

public:

	void setSeedBedOwner(ASeedBedItem* selectorItem);

	void OnItemSelected(const TSubclassOf<APlant>& selectedPlant);

};
