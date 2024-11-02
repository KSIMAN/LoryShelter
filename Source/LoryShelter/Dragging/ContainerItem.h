// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactions/InteractItem.h"
#include "ContainerItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API AContainerItem : public AInteractItem
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Default Constructor
	AContainerItem();
	bool isEmpty;
};
