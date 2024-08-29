// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Sittable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USittable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API ISittable
{
	GENERATED_BODY()
public:
	virtual FVector GetPointToSeat() = 0;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
};
