// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldArea.h"

// Sets default values
AWorldArea::AWorldArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	sceneComp = CreateDefaultSubobject<USceneComponent>("Scene Comp");

}

void AWorldArea::setAreaName(const FName& newName)
{
	
}

bool AWorldArea::checkActorInArea(AActor* actorToCheck)
{
	double distance = FVector::DistXY(GetActorLocation(), actorToCheck->GetActorLocation());
	
	if (distance <= areaRadius)
		return true;
	
	return false;
}

// Called when the game starts or when spawned
void AWorldArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

