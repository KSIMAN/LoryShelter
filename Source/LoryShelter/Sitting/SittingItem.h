// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sittable.h"
#include "../Interactions/InteractItem.h"
#include "SittingItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API ASittingItem : public AInteractItem, public ISittable
{
	GENERATED_BODY()
public:

	ASittingItem();

	//--Interaction Interface------------------------------------------------------------------------------------
	virtual void OnInteract(IInteractor* playerPtr)override;
protected:
	
	//returns center point of sitting item
	virtual FVector GetPointToSeat() override;

};
