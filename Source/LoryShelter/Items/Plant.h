// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Components/WidgetComponent.h"

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

	//--Helper functions---------------------------------------
	
	//Change timer text
	void refreshTimeInfoText();

	//Check if grow phase is done
	void checkGrowPhase();

	//Increases grow phase
	void increaseGrowPhase();

	//calculates The grow offset for phase increasing by class members mesh height and numPhases
	float calcGrowOffset();

	//calculates The grow offset for phase increasing
	float calcGrowOffset(float meshHeight, int PhasesNum);

	//calculates Mesh height
	float getPlantHeight(UStaticMesh* plantMesh);

	//--Components------------------------------------------

	//To show info about plant and time of growing
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UTextRenderComponent* timerText;

	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UWidgetComponent* timerWidget;

	//Plant Mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* itemMesh;

	//--Variables------------------------------------------
	
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


	//Grow Z offset for one phase
	float growOffset; 



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
