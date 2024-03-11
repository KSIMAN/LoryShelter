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

	//--Getters------------------------------------------

	bool getIsBusy() const { return isBusy; };

	//--Setters------------------------------------------

	void toggleIsBusy();

	//--Interaction Interface------------------------------------------------------------------------------------

	virtual void Interact(ALoryShelterCharacter* playerPtr)override;


protected:

	//--Variables----------------------------------------

	//is Raised
	bool isBusy;

	//-----------------------------------

	FVector findSeatPoint();

};
