// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "LoryShelter/Interactions/InteractItem.h"
#include "Door.generated.h"

UCLASS()
class LORYSHELTER_API ADoor : public AInteractItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Interaction process
	virtual void OnInteract(IInteractor* playerPtr) override;
	virtual void OnEndInteract(IInteractor* playerPtr) override;

	//-----------------------

	//Updates Door Position
	UFUNCTION()
	void UpdatePosition(float Output);

	//End of timeline
	UFUNCTION()
	void EndUpdatePosition();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Door Settings")
	UCurveFloat* InteractionCurve; //TODO: МБ в интерактион айтем?

	FTimeline InteractTimeLine;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Door Settings")
	UTimelineComponent* TimelineComponent;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	IInteractor* DoorInteractor;
	float MinYaw;
	float MaxYaw;
};
