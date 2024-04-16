// Fill out your copyright notice in the Description page of Project Settings.


#include "AliasHolderWidget.h"
#include "AliasGameplay.h"

bool UAliasHolderWidget::showAlias(const EAliasIndex& index, const FInteractionInfo& info)
{
	UAliasGameplay* alias = *aliasses.Find(index);

	if (alias == nullptr)
		return false;

	alias->SetVisibility(ESlateVisibility::Visible);
	alias->refreshItemAlias(info);
	return true;
}

bool UAliasHolderWidget::showAlias(EAliasIndex index)
{
	UAliasGameplay* alias = *aliasses.Find(index);

	if (!alias)
		return false;

	alias->SetVisibility(ESlateVisibility::Visible);
	return true;
}

bool UAliasHolderWidget::hideAlias(EAliasIndex index)
{
	UAliasGameplay* alias = *aliasses.Find(index);

	if (!alias)
		return false;

	alias->SetVisibility(ESlateVisibility::Collapsed);
	return true;
}

bool UAliasHolderWidget::createAlias(const EAliasIndex& aliasType)
{
	int32 index = static_cast<int32>(aliasType);
	if (aliasSubClasses[index] /*&& !*aliasses.Find(aliasType)*/)
	{

		UAliasGameplay* newAlias;
		newAlias = CreateWidget<UAliasGameplay>(GetWorld(), aliasSubClasses[index]);
		aliasLayout->AddChild(newAlias);
		newAlias->AddToViewport(999);
		newAlias->SetVisibility(ESlateVisibility::Collapsed);
		aliasses.Add(aliasType, newAlias);
		return true;
	}
	return false;
}

void UAliasHolderWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}
