// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Dragger.h"
#include "Draggable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UDraggable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LORYSHELTER_API IDraggable
{
	GENERATED_BODY()

public:
	//After Dragger Puts Up Item
	virtual void OnPutUp(IDragger*) = 0;
	//After Dragger Puts Down Item
	virtual void OnPutDown(IDragger*) = 0;
};
