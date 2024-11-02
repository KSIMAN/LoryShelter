// Fill out your copyright notice in the Description page of Project Settings.


#include "Animal.h"
#include "Components/CapsuleComponent.h"
#include "LoryShelter/Interactions/IInteractor.h"

// Sets default values
AAnimal::AAnimal() : hunger(maxHunger),
                     hungerCoeff(0.05), satisfaction(maxSatisfaction),
                     mindState(EAnimalMindState::NORMAL), satisfactCoeff(0.01)
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
	constexpr int happyVal = 80;
	constexpr int neutralVal = 40;

	if (hunger > happyVal && satisfaction > happyVal)
	{
		return EAnimalMindState::HAPPY;
	}
	if (hunger > neutralVal && satisfaction > neutralVal)
	{
		return EAnimalMindState::NORMAL;
	}
	return EAnimalMindState::SAD;
}

void AAnimal::diffIndicators()
{
	if (hunger > 0)
	{
		hunger -= hunger * hungerCoeff;
	}

	if (satisfaction > 0)
	{
		satisfaction -= satisfaction * satisfactCoeff;
	}

	OnIndicatorsUpdate();
}

void AAnimal::OnIndicatorsUpdate()
{
	mindState = recalcMindState();
}

void AAnimal::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                             const FHitResult& SweepResult)
{
	//Handling here, cause overlap event for Item not so often, as for Player Character

	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
	{
		OnStartFocus(loryPlayer);
	}
}

void AAnimal::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex)
{
	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
	{
		OnEndFocus(loryPlayer);
	}
}

void AAnimal::OnBeginInteract(IInteractor* playerPtr)
{
}

void AAnimal::OnEndInteract(IInteractor* playerPtr)
{
}

void AAnimal::OnStartFocus(IInteractor* playerPtr)
{
	if (!playerPtr) //*|| playerPtr->getFocusItem()) //if focus item != nullptr - object has another interaction
	{
	}

	//*playerPtr->setFocusItem(this);
	//*playerPtr->getPlayerHUD()->showAliasInteract(petInteractInfo, static_cast<EAliasIndex>(0));
}

void AAnimal::OnEndFocus(IInteractor* playerPtr)
{
	if (!playerPtr)
	{
	}

	//*playerPtr->setFocusItem(nullptr);
	//*playerPtr->getPlayerHUD()->hideAliasInteract(static_cast<EAliasIndex>(0)); //Item intract index = 0
}

UAnimMontage* AAnimal::GetInteractAnimation()
{
	return nullptr;
}

const FInteractionInfo& AAnimal::GetInteractionInfo()
{
	return petInteractInfo;
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
