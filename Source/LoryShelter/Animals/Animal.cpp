// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AAnimal::AAnimal() : mindState(EAnimalMindState::NORMAL), 
satisfaction(maxSatisfaction), satisfactCoeff(0.01),
hunger(maxHunger), hungerCoeff(0.05)
{
	interactCollider = CreateDefaultSubobject<UCapsuleComponent>("InteractCollider");
	//btAsset = CreateDefaultSubobject<UBehaviorTree>("Behavior Tree");
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

