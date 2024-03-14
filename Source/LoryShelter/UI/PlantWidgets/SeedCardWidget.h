// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/TextBlock.h"
#include "SeedCardWidget.generated.h"

/**
 * 
 */
class APlant;
class USeedbedSelectorWidget;

USTRUCT(BlueprintType)
struct FSeedCardInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FSeedCardInfo() {};

	//Name of plant
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText seedName;

	//Plant description 
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FText seedDesc;

	//Price to plant this seed in coins
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int seedPrice; 

	//
	//UTexture2D seedImage;

	//
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<APlant> plantClass;
};

UCLASS()
class LORYSHELTER_API USeedCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//Refresh by class member reference
	void refreshWidgetInfo();

	//Setting up widget selector
	void setSelectorOwner(USeedbedSelectorWidget* owner);

	USeedCardWidget(const FObjectInitializer& ObjectInitializer);

protected:


	//--UI Components-----------------------------------------------
	
	//Properties of seed
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FSeedCardInfo itemInfo;

	//Button of trying to plant seed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* plantSeedButton;

	//Price of seed text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* seedPriceText;

	//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* seedNameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* seedDescText;

	//Image of seed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* seedImage;

	//
	FColor errorColor;

	//---------------------------------------------

	//Owmer Selector Pointer
	USeedbedSelectorWidget* ownerSelector;

	//--Dynamic Delegates------------------------
	
	//
	UFUNCTION()
	void onClickPlantSeedButton();

	//--Native Events----------------------------

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
};
