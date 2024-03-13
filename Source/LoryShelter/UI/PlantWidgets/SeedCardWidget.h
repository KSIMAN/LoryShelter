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


USTRUCT(BlueprintType)
struct FSeedCardInfo
{
	GENERATED_USTRUCT_BODY()

	FSeedCardInfo() {};
	//Name of plant
	FText seedName;

	//Plant description 
	FText seedDesc;

	//Price to plant this seed in coins
	int seedPrice; 

	//
	//UTexture2D seedImage;

	//
	TSubclassOf<APlant> plantClass;
};

UCLASS()
class LORYSHELTER_API USeedCardWidget : public UUserWidget
{
	GENERATED_BODY()
	
	//Maybe deprecated. 
	void refreshReference(const FSeedCardInfo& newInfo);

public:
	//Refresh by class member reference
	void refreshWidgetInfo();

	USeedCardWidget(const FObjectInitializer& ObjectInitializer);

protected:

	//Properties of seed
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
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

	//--Native Events----------------------------

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
};
