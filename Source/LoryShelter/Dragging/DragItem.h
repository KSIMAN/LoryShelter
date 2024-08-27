// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactions/InteractItem.h"
#include "DragItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API ADragItem : public AInteractItem
{
	GENERATED_BODY()
public:

	ADragItem();
	virtual ~ADragItem() {};
	//--Interaction Interface------------------------------------------------------------------------------------

	virtual void OnInteract(IInteractor* playerPtr) override;
	
};
