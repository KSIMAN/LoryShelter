// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"
#include "Components/CapsuleComponent.h"
#include "LoryShelter/Interactions/IInteractor.h"

// Sets default values
AAnimal::AAnimal() : mindState(EAnimalMindState::NORMAL), 
satisfaction(maxSatisfaction), satisfactCoeff(0.01),
hunger(maxHunger), hungerCoeff(0.05)
{
	interactCollider = CreateDefaultSubobject<UCapsuleComponent>("InteractCollider");
	interactCollider->SetupAttachment(GetMesh());
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(180);

}

// Called when the game starts or when spawned
void AAnimal::BeginPlay()
{
	Super::BeginPlay();
	interactCollider->OnComponentBeginOverlap.AddDynamic(this, &AAnimal::OnOverlapBegin);
	interactCollider->OnComponentEndOverlap.AddDynamic(this, &AAnimal::OnOverlapEnd);
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
void AAnimal::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Handling here, cause overlap event for Item not so often, as for Player Character

	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
		OnStartFocus(loryPlayer);
}

void AAnimal::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
		OnEndFocus(loryPlayer);
}

void AAnimal::OnBeginInteract(IInteractor* playerPtr)
{
	
}

void AAnimal::OnEndInteract(IInteractor* playerPtr)
{
}

void AAnimal::OnStartFocus(IInteractor* playerPtr)
{
	if (!playerPtr)//*|| playerPtr->getFocusItem()) //if focus item != nullptr - object has another interaction
		return;

	//*playerPtr->setFocusItem(this);
	//*playerPtr->getPlayerHUD()->showAliasInteract(petInteractInfo, static_cast<EAliasIndex>(0));
}

void AAnimal::OnEndFocus(IInteractor* playerPtr)
{
	if (!playerPtr )
		return;

	//*playerPtr->setFocusItem(nullptr);
	//*playerPtr->getPlayerHUD()->hideAliasInteract(static_cast<EAliasIndex>(0)); //Item intract index = 0
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

