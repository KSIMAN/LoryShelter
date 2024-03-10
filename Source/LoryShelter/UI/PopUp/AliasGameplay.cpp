// Fill out your copyright notice in the Description page of Project Settings.


#include "AliasGameplay.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>
#include "../../Items/InteractItem.h"


void UAliasGameplay::refreshItemAlias(const FInteractionInfo& interactInfo)
{
	//AliasText->SetText(FText::Format(NSLOCTEXT("AliasGameplay", "AliasText", "Press F to {0}"), interactInfo.interactAlias));
	AliasText->SetText(FText::FromString(interactInfo.interactAlias));
}

void UAliasGameplay::NativeOnInitialized()
{
	UUserWidget::NativeOnInitialized();
}

void UAliasGameplay::NativeConstruct()
{
	UUserWidget::NativeConstruct();
}
