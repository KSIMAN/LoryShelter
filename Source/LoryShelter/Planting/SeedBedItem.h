// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantZone.h"
#include "Components/WidgetComponent.h"
#include "../Interactions/InteractItem.h"
#include "SeedBedItem.generated.h"

/**
 * 
 */
class APlant;

UCLASS()
class LORYSHELTER_API ASeedBedItem : public AInteractItem, public IPlantZone
{
	GENERATED_BODY()

public:
	//Set Grown Plant to slot returns success status
	virtual bool AddPlant(IPlantable* newPlant) override;

	//Set Grown Plant to slot returns success status
	bool AddPlantByClass(const TSubclassOf<APlant>& newPlantClass);

	//Clearing plant slot. Returns pointer for plant thant was in slot
	virtual IPlantable* RemovePlant() override;

protected:
	//Timeer
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UWidgetComponent* TimerWidgetComponent;

	//Plant Timer Widget
	class UPlantTimerWidget* timerWidgetPtr;

	void OnNeedUpdateTimer();
	//---------------------------------------------------------

	//Contains growing plant
	IPlantable* plantSlot;

	//While SeedBed Selector not ready
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class USeedbedSelectorWidget> selectorWidgetClass; //maybe put this int HUD for player

public:
	ASeedBedItem();

	//--Interaction Interface--------------------------------------------

	virtual void OnBeginInteract(IInteractor* playerPtr) override;

	virtual void OnInteract(IInteractor* playerPtr) override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
