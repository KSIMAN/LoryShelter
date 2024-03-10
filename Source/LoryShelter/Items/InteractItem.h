// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/InteractionInterface.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "InteractItem.generated.h"


USTRUCT(BlueprintType)
struct FInteractionInfo
{
	GENERATED_USTRUCT_BODY()

	//Item name
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FName itemName;

	//Alias to show before interacting
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText interactAlias;

};

UCLASS()
class LORYSHELTER_API AInteractItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
