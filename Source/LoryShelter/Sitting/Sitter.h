// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sittable.h"
#include "UObject/Interface.h"
#include "Sitter.generated.h"

// This class does not need to be modified.
UINTERFACE()
class USitter : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API ISitter
{
	GENERATED_BODY()
public:
	virtual uint8 SitDown(ISittable* item) = 0;
	virtual uint8 SitUp(ISittable* item) = 0;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
