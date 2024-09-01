// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Plantable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UPlantable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API IPlantable
{
	GENERATED_BODY()

	virtual float getPlantHeight() = 0;
public:
};
