// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WrapBox.h"
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
	TArray<TSubclassOf<USeedCardWidget>> itemsToShowClasses;

	//Seed cards Wrap Box
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UWrapBox* seedCardsHolder;

	//Ownet item Ptr
	ASeedBedItem* ownerItem;
	
	void refreshSeedCards();

	//
	virtual void NativeOnInitialized() override;
	
	//When widget closes
	virtual void BeginDestroy() override;



public:

	void setSeedBedOwner(ASeedBedItem* selectorItem);

	void OnItemSelected(const TSubclassOf<APlant>& selectedPlant);

};
