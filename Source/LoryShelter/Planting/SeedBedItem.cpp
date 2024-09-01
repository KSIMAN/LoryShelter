// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedBedItem.h"
#include "PlantWidgets/SeedbedSelectorWidget.h"
#include "Plant.h"


bool ASeedBedItem::AddPlant(IPlantable* newPlant)
{
	if (plantSlot)
		return false; //Slot is Busy

	plantSlot = newPlant;

	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("HARVEST")), FText::FromStringTable(FName("ActionsST"), TEXT("PLANT")));

	return true;
}

bool ASeedBedItem::AddPlantByClass(const TSubclassOf<APlant>& newPlantClass)
{
	if (plantSlot)
		return false; //Slot is Busy

	return AddPlant(Cast<IPlantable>(GetWorld()->SpawnActor(newPlantClass.Get(), &GetActorTransform())));
}

IPlantable* ASeedBedItem::RemovePlant()
{
	//need to throw exeption if plantSlot == nullptr on func entry

	IPlantable* returnVal = nullptr;

	Swap(plantSlot, returnVal);

	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("HARVEST")), FText::FromStringTable(FName("ActionsST"), TEXT("PLANT")));

	return returnVal;
}

ASeedBedItem::ASeedBedItem() : AInteractItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("SEEDBED"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("PLANT"));
	itemInfo.interactDuration = 3;
}

void ASeedBedItem::OnBeginInteract(IInteractor* playerPtr)
{
	//Create Plant Widget Here
}

void ASeedBedItem::OnInteract(IInteractor* playerPtr)
{
	Super::OnInteract(playerPtr);

	if (!selectorWidgetClass)
		return;

	USeedbedSelectorWidget* selectorWidget = CreateWidget<USeedbedSelectorWidget>(GetWorld(), selectorWidgetClass);
	selectorWidget->AddToViewport(1000);
	selectorWidget->SetVisibility(ESlateVisibility::Visible);
	selectorWidget->setSeedBedOwner(this);

	//While SeedBed Selector not ready
	//if (!plantType) return;
	//plantSlot = Cast<APlant>(GetWorld()->SpawnActor(plantType.Get(), &GetActorTransform()));
	if (!plantSlot)
		return;
}