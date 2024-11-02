// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PopUp/AliasHolderWidget.h"
#include "LoryHUD.generated.h"

struct FInteractionInfo;
/**
 * 
 */
UCLASS()
class LORYSHELTER_API ALoryHUD : public AHUD
{
	GENERATED_BODY()

public:
	void showAliasInteract(const FInteractionInfo& interactInfo, EAliasIndex aliasType);
	void hideAliasInteract(EAliasIndex aliasType);

protected:
	//--Subclasses----------------------------------------------

	//Subclass for alias widget
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAliasHolderWidget> AliasWidgetClass;

	//--Widget Pointers-----------------------------------------

	//Alias Widget Pointer
	UPROPERTY()
	UAliasHolderWidget* aliasHolderWidget;

	virtual void BeginPlay() override;
};
