// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactions/InteractItem.h"
#include "SeedBedItem.generated.h"

/**
 * 
 */
class APlant;

UCLASS()
class LORYSHELTER_API ASeedBedItem : public AInteractItem
{
	GENERATED_BODY()

public:
	//--Setters-----------------------------------------

	//Set Grown Plant to slot returns success status
	bool addPlantToSlot(APlant* newPlant);

	//Set Grown Plant to slot returns success status
	bool addPlantToSlot(const TSubclassOf<APlant>& newPlantClass);

	//Clearing plant slot. Returns pointer for plant thant was in slot
	APlant* freePlantSlot();


protected:

	//Contains growing plant
	 APlant* plantSlot;

	//While SeedBed Selector not ready
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class USeedbedSelectorWidget> selectorWidgetClass; //maybe put this int HUD for player

	
	

public:
	ASeedBedItem();

	//--Interaction Interface--------------------------------------------

	virtual void OnBeginInteract(IInteractor* playerPtr) override;

	virtual void OnInteract(IInteractor* playerPtr)override;
};
