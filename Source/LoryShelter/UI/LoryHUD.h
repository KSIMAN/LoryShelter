// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LoryHUD.generated.h"

class UAliasGameplay;
struct FInteractionInfo;
/**
 * 
 */
UCLASS()
class LORYSHELTER_API ALoryHUD : public AHUD
{
	GENERATED_BODY()

public:

	void showAliasInteract(const FInteractionInfo& interactInfo);
	void hideAliasInteract();
protected:

	//--Subclasses----------------------------------------------

	//Subclass for alias widget
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAliasGameplay> AliasWidgetClass;

	//--Widget Pointers-----------------------------------------

	//Alias Widget Pointer
	UPROPERTY()
	UAliasGameplay* aliasWidget;

	virtual void BeginPlay() override;

	
};
