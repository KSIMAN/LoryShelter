// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedBedItem.h"
#include "../UI/PlantWidgets/SeedbedSelectorWidget.h"
#include "Plant.h"



ASeedBedItem::ASeedBedItem() : AInteractItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("SEEDBED"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("PLANT"));
	itemInfo.interactDuration = 3;

	
}

void ASeedBedItem::beginInteract(ALoryShelterCharacter* playerPtr)
{
	//Create Plant Widget Here

}

void ASeedBedItem::Interact(ALoryShelterCharacter* playerPtr)
{
	Super::Interact(playerPtr);


	//USeedbedSelectorWidget* selectorWidget = CreateWidget<USeedbedSelectorWidget>(GetWorld(), selectorWidSubclass);
	//aliasWidget->AddToViewport(999);
	//aliasWidget->SetVisibility(ESlateVisibility::Visible);
	//While SeedBed Selector not ready
	//if (!plantType) return;
	//plantSlot = Cast<APlant>(GetWorld()->SpawnActor(plantType.Get(), &GetActorTransform()));
	
	//ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("HARVEST")), FText::FromStringTable(FName("ActionsST"), TEXT("PLANT")));
	//
	if (!plantSlot)
		return;


}