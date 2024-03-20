// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "WorldArea.generated.h"

UCLASS()
class LORYSHELTER_API AWorldArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldArea();

	//--Setters---------------------------------------
	
	//change area name 
	void setAreaName(const FName& newName);

	//Area radius
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float areaRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* sceneComp;

	//returns true if actor is in current area
	bool checkActorInArea(AActor* actorToCheck);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
