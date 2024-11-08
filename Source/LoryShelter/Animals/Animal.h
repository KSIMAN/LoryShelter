// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interactions/IInteractable.h"
#include "BehaviorTree/BehaviorTree.h"
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
class LORYSHELTER_API AAnimal : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAnimal();

	UBehaviorTree* getBTAsset() { return btAsset; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//--SubObjects--------------------------------------

	//Interaction Collider
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* interactCollider;

	//BT asset
	UPROPERTY(EditAnywhere, BlueprintReadwrite, Category = "AI")
	class UBehaviorTree* btAsset;

	//--Variables---------------------------------------

	//Pet's satiety
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int hunger;

	//diff Hunger coeff
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	double hungerCoeff;

	//Pet's happines
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int satisfaction;

	//Animal mind state
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	EAnimalMindState mindState;

	//Happiness down coeff
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	double satisfactCoeff;


	//--Helper functions----------------------------

	EAnimalMindState recalcMindState();

	//To became hungrier and more unhappy
	void diffIndicators();

	//Refreshes info about hunger and satisfaction
	virtual void OnIndicatorsUpdate();

	//--Overlap events-----------------------------------
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);

public:
	//--Interaction Interface------------------------------------------------------------------------------------

	//virtual void Interact(ALoryShelterCharacter* playerPtr)override;

	virtual void OnBeginInteract(IInteractor* playerPtr) override;

	virtual void OnEndInteract(IInteractor* playerPtr) override;

	virtual void OnStartFocus(IInteractor* playerPtr) override;

	virtual void OnEndFocus(IInteractor* playerPtr) override;

	//
	virtual UAnimMontage* GetInteractAnimation() override;
	//
	virtual const FInteractionInfo& GetInteractionInfo() override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInteractionInfo petInteractInfo;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
