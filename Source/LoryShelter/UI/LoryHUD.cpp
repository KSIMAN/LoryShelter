// Fill out your copyright notice in the Description page of Project Settings.


#include "LoryHUD.h"
#include "PopUp/AliasGameplay.h"


void ALoryHUD::showAliasInteract(const FInteractionInfo& interactInfo, EAliasIndex aliasType)
{
	if (!aliasHolderWidget)
	{
		return;
	}

	check(aliasHolderWidget->showAlias(aliasType, interactInfo));
}

void ALoryHUD::hideAliasInteract(EAliasIndex aliasType)
{
	if (!aliasHolderWidget)
	{
		return;
	}

	check(aliasHolderWidget->hideAlias(aliasType));
}

void ALoryHUD::BeginPlay()
{
	Super::BeginPlay();

	if (AliasWidgetClass)
	{
		aliasHolderWidget = CreateWidget<UAliasHolderWidget>(GetWorld(), AliasWidgetClass);
		aliasHolderWidget->AddToViewport(999);
		aliasHolderWidget->SetVisibility(ESlateVisibility::Visible);

		aliasHolderWidget->createAlias(EAliasIndex::ITEM);
		aliasHolderWidget->createAlias(EAliasIndex::PET);
	}
}
