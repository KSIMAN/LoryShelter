// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"

#include "Plant.generated.h"

UCLASS()
class LORYSHELTER_API APlant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlant();

	//--Setters---------------------------------------
	

protected:

	//Change timer text
	void refreshTimeInfoText();

	void checkGrowPhase();

	void increaseGrowPhase();

	//To show info about plant and time of growing
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UTextRenderComponent* timerText;

	//Plant Mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* itemMesh;

	//Plant Time In seconds
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	int plantTime;

	//How mach remained
	int plantTimeRemained;

	//Current grow phase
	int currGrowPhase;

	//Max number of Phases. Last Phase == GROWN
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	int maxPhase;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
