// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AnimalController.generated.h"

/**
 * 
 */
UCLASS()
class LORYSHELTER_API AAnimalController : public AAIController
{
	GENERATED_BODY()
public:
	AAnimalController(const FObjectInitializer& ObjectInitializer);

	//--Base--------------------------------------------------------
	virtual void OnPossess(APawn* InPawn) override;
	//--Getters-----------------------------------------------------

	//Returns BlackBoard Component, used by this controller
	UBlackboardComponent* getBlackBoardComp();

	//Returns Behavior tree used by this controller
	UBehaviorTreeComponent* getBehaviourTreeComp();
protected:
	
	UPROPERTY(transient)
	class UBehaviorTreeComponent* BTC;

	UPROPERTY(transient)
	class UBlackboardComponent* BBC;

	//--BB Key Values----------------

	FName playerActorKey;

	FBlackboard::FKey CreatureKeyId;
	

};
