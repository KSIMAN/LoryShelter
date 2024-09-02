// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "CoreFwd.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(1.);

	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlantMesh");

	rootNode = CreateDefaultSubobject<USceneComponent>("Scene Component");
	
	RootComponent = rootNode;

	itemMesh->SetupAttachment(RootComponent);

	plantTime = 10.;
	plantTimeRemained = plantTime;
	maxPhase = 5;
	currGrowPhase = 0;

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
	itemMesh->AddWorldOffset(FVector(0, 0, growOffset));
	/*if (currGrowPhase == maxPhase)
		timerText->SetText(FText::FromString("Ready to harvest"));*/
	//Progress Visualisation Later
}

float APlant::calcGrowOffset()
{
	float meshHeight = getPlantHeight();
	return calcGrowOffset(meshHeight, maxPhase);
}

float APlant::calcGrowOffset(float meshHeight, int PhasesNum)
{
	return meshHeight/PhasesNum;
}

float APlant::getPlantHeight()
{
	return static_cast<double>(itemMesh->GetStaticMesh()->GetBoundingBox().GetSize().Z * 4);
}

int APlant::GetGrowTimeRemained()
{
	return (plantTime * (maxPhase - currGrowPhase) + plantTimeRemained);
}

FName APlant::GetPlantName()
{
	return FName("PLANT");
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

	//Set up plant start position
	growOffset = calcGrowOffset();
	float groundedHeight = growOffset * maxPhase * 2;
	itemMesh->AddWorldOffset(FVector(0, 0, -groundedHeight));

}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (currGrowPhase != maxPhase)
	{
		TimeUpdateDelegate.Broadcast();
		checkGrowPhase();
		plantTimeRemained--;
	}
}

