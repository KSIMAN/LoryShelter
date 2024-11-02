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

public:
	//returns Max Plant Height
	virtual float getPlantHeight() = 0;

	virtual FName GetPlantName() = 0;

	//Returns remained time to grow in seconds
	virtual int GetGrowTimeRemained() = 0;
};
