// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractItem.h"
#include "SittingItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API ASittingItem : public AInteractItem
{
	GENERATED_BODY()
public:

	ASittingItem();

	//--Interaction Interface------------------------------------------------------------------------------------

	virtual void Interact(ALoryShelterCharacter* playerPtr)override;


protected:

	//-----------------------------------

	//returns center point of sitting item
	FVector findSeatPoint();

};
