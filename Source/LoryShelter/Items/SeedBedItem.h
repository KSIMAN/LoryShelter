// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractItem.h"
#include "SeedBedItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API ASeedBedItem : public AInteractItem
{
	GENERATED_BODY()
protected:

	//Contains growing plant
	class APlant* plantSlot;

	//While SeedBed Selector not ready
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<APlant> plantType;

public:
	ASeedBedItem();

	//--Interaction Interface--------------------------------------------

	virtual void beginInteract(ALoryShelterCharacter* playerPtr) override;

	virtual void Interact(ALoryShelterCharacter* playerPtr)override;
};
