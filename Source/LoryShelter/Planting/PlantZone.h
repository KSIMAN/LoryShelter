// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plantable.h"
#include "UObject/Interface.h"
#include "PlantZone.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPlantZone : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API IPlantZone
{
	GENERATED_BODY()

	//Set Grown Plant to slot returns success status
	virtual bool AddPlant(IPlantable* newPlant) = 0;

	//Clearing plant slot. Returns pointer for plant thant was in slot
	virtual IPlantable* RemovePlant() = 0;
};
