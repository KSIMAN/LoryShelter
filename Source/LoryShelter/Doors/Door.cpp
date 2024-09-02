// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"


// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>("Timeline");
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("DOOR"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("OPEN"));
	itemInfo.interactDuration = 3;
	
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	MinYaw = itemMesh->GetRelativeRotation().Yaw;
	MaxYaw = MinYaw + 90.f;
	TimelineComponent->SetTimelineLength(1.f);

	FOnTimelineFloat ProgressUpdate;
	ProgressUpdate.BindUFunction(this, FName("UpdatePosition"));

	FOnTimelineEvent FinishUpdate;
	FinishUpdate.BindUFunction(this, FName("EndUpdatePosition"));

	TimelineComponent->AddInterpFloat(InteractionCurve, ProgressUpdate);
	TimelineComponent->SetTimelineFinishedFunc(FinishUpdate);
}

void ADoor::OnInteract(IInteractor* playerPtr)
{
	DoorInteractor = playerPtr;
	if(!bItemUsed)
		TimelineComponent->Play();
	else
		TimelineComponent->Reverse();
}

void ADoor::OnEndInteract(IInteractor* playerPtr)
{
}

void ADoor::UpdatePosition(float Output)
{
	FRotator DoorRotator = itemMesh->GetComponentRotation();
	DoorRotator.Yaw = FMath::Lerp(MinYaw, MaxYaw, Output);
	itemMesh->SetRelativeRotation(DoorRotator);
}

void ADoor::EndUpdatePosition()
{
	//TODO: Дубляж убери уже, пора бы
	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("CLOSE")), FText::FromStringTable(FName("ActionsST"), TEXT("OPEN")));

	if(DoorInteractor)
	{
		//Move to Refocus function
		OnEndFocus(DoorInteractor);
		OnStartFocus(DoorInteractor);
	}
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//InteractTimeLine.TickTimeline(DeltaTime);
}

