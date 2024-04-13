// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interfaces/InteractionInterface.h"
#include "Animal.generated.h"

UENUM(BlueprintType)
enum class EAnimalMindState : uint8
{
	HAPPY,
	NORMAL,
	SAD
};
class ALoryShelterCharacter;

constexpr int maxHunger = 100;
constexpr int maxSatisfaction = 100;

UCLASS()
class LORYSHELTER_API AAnimal : public ACharacter, public IInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//--SubObjects--------------------------------------

	//
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* interactCollider;

	//--Variables---------------------------------------

	//Pet's satiety
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int hunger;

	//diff Hunger coeff
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int hungerCoeff;

	//Pet's happines
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int satisfaction;

	//Animal mind state
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	EAnimalMindState mindState;

	//Happiness down coeff
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int satisfactCoeff;


	//--Helper functions----------------------------
	
	EAnimalMindState recalcMindState();

	//To became hungrier and more unhappy
	void diffIndicators();

	//Refreshes info about hunger and satisfaction
	virtual void OnIndicatorsUpdate();


public:	

	//--Interaction Interface------------------------------------------------------------------------------------

	//virtual void Interact(ALoryShelterCharacter* playerPtr)override;

	//virtual void beginInteract(ALoryShelterCharacter* playerPtr) override;

	//virtual void endInteract(ALoryShelterCharacter* playerPtr) override;

	//virtual void beginFocus(ALoryShelterCharacter* playerPtr) override;

	//virtual void endFocus(ALoryShelterCharacter* playerPtr) override;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//FInteractionInfo petInteractInfo;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};