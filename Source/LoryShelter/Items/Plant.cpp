// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(1.);

	timerText = CreateDefaultSubobject<UTextRenderComponent>("Text Render Component");
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlantMesh");

	timerText->AddLocalOffset(FVector(0, 0, 60)); //
	itemMesh->SetupAttachment(timerText);


	plantTime = 10.;
	plantTimeRemained = plantTime;
	maxPhase = 5;
	currGrowPhase = 0;

	//
	itemMesh->AddLocalOffset(FVector(0, 0, -10 * maxPhase)); //Move 10 to growConst
}

void APlant::refreshTimeInfoText()
{
	//Add  00:00:00 format function later
	timerText->SetText(FText::AsNumber(plantTime * (maxPhase - currGrowPhase) + plantTimeRemained));
}

void APlant::checkGrowPhase()
{
	if (plantTimeRemained <= 0)
		increaseGrowPhase();
}

void APlant::increaseGrowPhase()
{
	plantTimeRemained = plantTime;
	currGrowPhase++;
	itemMesh->AddLocalOffset(FVector(0, 0, 10));
	itemMesh->SetRelativeScale3D(itemMesh->GetRelativeScale3D() + FVector(1, 1, 1) * 0.1 * currGrowPhase);
	if (currGrowPhase == maxPhase)
		timerText->SetText(FText::FromString("Ready to harvest"));
	//Progress Visualisation Later
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (currGrowPhase != maxPhase)
	{
		refreshTimeInfoText();
		checkGrowPhase();
		plantTimeRemained--;
	}
	else 
		PrimaryActorTick.bCanEverTick = false;
	

}

