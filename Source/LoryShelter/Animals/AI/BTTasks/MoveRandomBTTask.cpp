// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveRandomBTTask.h"
#include "../AnimalController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UMoveRandomBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FVector vNewLocation;
	FNavLocation vNavLoc;

	AActor* pOwner = OwnerComp.GetAIOwner();
	if (!pOwner)
		return EBTNodeResult::Failed;
	FVector vRadOrigin = pOwner->GetActorLocation(); //Radius origin
	vRadOrigin += FVector(FMath::FRandRange(-600.0f, 600.0f), FMath::FRandRange(-600.f, 600.f), 0);
	if (!UNavigationSystemV1::GetCurrent(GetWorld())->GetRandomPointInNavigableRadius(vRadOrigin, 1000.0f,
		vNavLoc))
		return EBTNodeResult::Failed;

	UBlackboardComponent* pBBRef = OwnerComp.GetBlackboardComponent();
	if (!pBBRef)
		return EBTNodeResult::Failed;
	vNewLocation = FVector(vNavLoc.Location.X, vNavLoc.Location.Y, vRadOrigin.Z);
	pBBRef->SetValueAsVector("MoveToLocation", vNewLocation); //Write Location
	
	//OwnerComp.GetAIOwner()->MoveToLocation(vNewLocation); //For test
	return EBTNodeResult::Succeeded;
}
