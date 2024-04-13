// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"

// Sets default values
AAnimal::AAnimal()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorTickInterval(180);

}

// Called when the game starts or when spawned
void AAnimal::BeginPlay()
{
	Super::BeginPlay();
	
}


EAnimalMindState AAnimal::recalcMindState()
{
	const int happyVal = 80;
	const int neutralVal = 40;

	if (hunger > happyVal && satisfaction > happyVal)
		return EAnimalMindState::HAPPY;
	else if (hunger > neutralVal && satisfaction > neutralVal)
		return EAnimalMindState::NORMAL;
	else
		return EAnimalMindState::SAD;
}

void AAnimal::diffIndicators()
{
	if(hunger > 0)
		hunger -= hunger * hungerCoeff;

	if (satisfaction > 0)
		satisfaction -= satisfaction * satisfactCoeff;

	OnIndicatorsUpdate();
}

void AAnimal::OnIndicatorsUpdate()
{
	mindState = recalcMindState();

}

// Called every frame
void AAnimal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	diffIndicators();

	
}

// Called to bind functionality to input
void AAnimal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

