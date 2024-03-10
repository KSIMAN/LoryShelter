// Fill out your copyright notice in the Description page of Project Settings.


#include "LoryHUD.h"
#include "PopUp/AliasGameplay.h"


void ALoryHUD::showAliasInteract(const FInteractionInfo& interactInfo)
{
	if (!aliasWidget)
		return;

	aliasWidget->refreshItemAlias(interactInfo);
	aliasWidget->SetVisibility(ESlateVisibility::Visible);
}

void ALoryHUD::hideAliasInteract()
{
	aliasWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void ALoryHUD::BeginPlay()
{
	Super::BeginPlay();
	
	if (AliasWidgetClass)
	{
		aliasWidget = CreateWidget<UAliasGameplay>(GetWorld(), AliasWidgetClass);
		aliasWidget->AddToViewport(999);
		aliasWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}
