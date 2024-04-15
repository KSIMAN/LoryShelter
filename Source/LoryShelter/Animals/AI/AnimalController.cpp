// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimalController.h"
#include "../Animal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"

AAnimalController::AAnimalController(const FObjectInitializer& ObjectInitializer) : AAIController(ObjectInitializer)
{
	BBC = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
	BTC = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	playerActorKey = FName("PlayerActor");
}

void AAnimalController::OnPossess(APawn * InPawn)
{
	Super::OnPossess(InPawn);
	AAnimal* pCreature = Cast<AAnimal>(InPawn);

	if (pCreature && pCreature->getBTAsset()) //Remove Tree asset from animal later and init here
	{
		
		BBC->InitializeBlackboard(*pCreature->getBTAsset()->BlackboardAsset);
		BBC->SetValueAsObject(playerActorKey, pCreature);

		CreatureKeyId = BBC->GetKeyID("TargetActor");
		BTC->StartTree(*pCreature->getBTAsset());
	}


}


UBlackboardComponent* AAnimalController::getBlackBoardComp()
{
	check(BBC != nullptr);
	return BBC;
}

UBehaviorTreeComponent* AAnimalController::getBehaviourTreeComp()
{
	check(BTC != nullptr);
	return BTC;
}
