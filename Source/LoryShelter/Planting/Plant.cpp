// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "PlantWidgets/PlantTimerWidget.h"
#include "CoreFwd.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(1.);

	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlantMesh");
	timerWidgetComp = CreateDefaultSubobject<UWidgetComponent>("Timer Widget");
	rootNode = CreateDefaultSubobject<USceneComponent>("Scene Component");
	
	RootComponent = rootNode;

	itemMesh->SetupAttachment(RootComponent);
	timerWidgetComp->SetupAttachment(RootComponent);
	plantTime = 10.;
	plantTimeRemained = plantTime;
	maxPhase = 5;
	currGrowPhase = 0;

}

void APlant::refreshTimeInfoText()
{
	if (timerWidgetPtr)
	{
		int timeInSeconds = plantTime * (maxPhase - currGrowPhase) + plantTimeRemained;
		timerWidgetPtr->setTimeRemained(timeInSeconds);
	}
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
	float meshHeight = getPlantHeight(itemMesh->GetStaticMesh().Get());
	return calcGrowOffset(meshHeight, maxPhase);
}

float APlant::calcGrowOffset(float meshHeight, int PhasesNum)
{
	return meshHeight/PhasesNum;
}

float APlant::getPlantHeight(UStaticMesh* plantMesh)
{
	return static_cast<double>(plantMesh->GetBoundingBox().GetSize().Z * 4);
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

	//Set up plant start position
	growOffset = calcGrowOffset();
	float groundedHeight = growOffset * maxPhase * 2;
	itemMesh->AddWorldOffset(FVector(0, 0, -groundedHeight));

	
	
	// Move to setUpItem func ----------------------------------------------------------------------------
	FSoftClassPath timerClassRef(TEXT("/Game/UI/Widgets/PlantTimerWidgetBP.PlantTimerWidgetBP_C"));

	UClass* timerWidgetClass = timerClassRef.TryLoadClass<UWidget>();
	
	if (timerWidgetClass)
	{
		timerWidgetComp->SetWidgetClass(timerWidgetClass);
		timerWidgetPtr = Cast<UPlantTimerWidget>(timerWidgetComp->GetWidget());
	}
		
	if (timerWidgetPtr)
		timerWidgetPtr->setItemName(FText(FText::FromString("Plant")));

	//---------------------------------------------------------------------------------------------------

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
}

