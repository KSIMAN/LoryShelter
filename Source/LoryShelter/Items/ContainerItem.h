// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractItem.h"
#include "ContainerItem.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API AContainerItem : public AInteractItem
{
	GENERATED_BODY()
	
public:
	//Default Constructor
	AContainerItem();

	bool isEmpty;
};
