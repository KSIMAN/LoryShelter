// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AliasGameplay.generated.h"

/**
 * 
 */

class UTextBlock;
class UProgressBar;
struct FInteractionInfo;

UCLASS()
class LORYSHELTER_API UAliasGameplay : public UUserWidget
{
	GENERATED_BODY()

public:
	void refreshItemAlias(const FInteractionInfo& interactInfo);

protected:
	//--Ui Components------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* KeyPressText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* AliasText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* NameText;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	//UProgressBar* interactProgBar; On Future

	//--Native Events----------------------------

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
};
