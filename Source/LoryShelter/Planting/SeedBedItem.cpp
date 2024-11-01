// Fill out your copyright notice in the Description page of Project Settings.


#include "SeedBedItem.h"
#include "PlantWidgets/SeedbedSelectorWidget.h"
#include "PlantWidgets/PlantTimerWidget.h"
#include "Plant.h"
#include "Kismet/GameplayStatics.h"


ASeedBedItem::ASeedBedItem()
{
	itemInfo.itemName = FText::FromStringTable(FName("ItemsST"), TEXT("SEEDBED"));
	itemInfo.interactAlias = FText::FromStringTable(FName("ActionsST"), TEXT("PLANT"));
	itemInfo.interactDuration = 3;

	TimerWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Timer Widget");
	if(itemMesh)
	TimerWidgetComponent->SetupAttachment(itemMesh);
	TimerWidgetComponent->SetVisibility(false);
}


void ASeedBedItem::BeginPlay()
{
	Super::BeginPlay();

		
	// Move to setUpItem func ----------------------------------------------------------------------------
	FSoftClassPath timerClassRef(TEXT("/Game/UI/Widgets/PlantTimerWidgetBP.PlantTimerWidgetBP_C"));

	UClass* timerWidgetClass = timerClassRef.TryLoadClass<UWidget>();
	
	if (timerWidgetClass)
	{
		TimerWidgetComponent->SetWidgetClass(timerWidgetClass);
		timerWidgetPtr = Cast<UPlantTimerWidget>(TimerWidgetComponent->GetWidget());
	}
		
	if (timerWidgetPtr)
		timerWidgetPtr->setItemName(FText(FText::FromString("Plant")));

}

void ASeedBedItem::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if(TimerWidgetComponent)
	{
		auto ViewRotator = TimerWidgetComponent->GetComponentRotation();
		auto PlayerRotator = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation();
		ViewRotator.Yaw = PlayerRotator.GetInverse().Yaw;
		ViewRotator.Pitch = PlayerRotator.GetInverse().Pitch;
		TimerWidgetComponent->SetWorldRotation(ViewRotator);
	}
}


bool ASeedBedItem::AddPlant(IPlantable* newPlant)
{
	if (plantSlot)
		return false; //Slot is Busy

	plantSlot = newPlant;

	APlant* PlantPtr = Cast<APlant>(newPlant);
	if(PlantPtr)
		PlantPtr->TimeUpdateDelegate.AddUObject(this, &ASeedBedItem::OnNeedUpdateTimer);

	//--Change Timer ---------------
	check(timerWidgetPtr)
	check(TimerWidgetComponent)
	
	timerWidgetPtr->setItemName(FText::FromName(PlantPtr->GetPlantName()));
	TimerWidgetComponent->SetVisibility(true);

	//--Item Usage-----------------
	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("HARVEST")), FText::FromStringTable(FName("ActionsST"), TEXT("PLANT")));

	return true;
}

bool ASeedBedItem::AddPlantByClass(const TSubclassOf<APlant>& newPlantClass)
{
	if (plantSlot)
		return false; //Slot is Busy

	return AddPlant(Cast<IPlantable>(GetWorld()->SpawnActor(newPlantClass.Get(), &GetActorTransform())));
}

IPlantable* ASeedBedItem::RemovePlant()
{
	//need to throw exeption if plantSlot == nullptr on func entry

	IPlantable* returnVal = nullptr;

	Swap(plantSlot, returnVal);

	
	ToggleItemUsed(FText::FromStringTable(FName("ActionsST"), TEXT("HARVEST")), FText::FromStringTable(FName("ActionsST"), TEXT("PLANT")));

	check(timerWidgetPtr)
	check(TimerWidgetComponent)
	
	//timerWidgetPtr->setItemName(FText::FromName(returnVal->GetPlantName()));
	TimerWidgetComponent->SetVisibility(false);
	
	return returnVal;
}

void ASeedBedItem::OnNeedUpdateTimer()
{
	if (timerWidgetPtr)
	{
		int timeInSeconds = plantSlot->GetGrowTimeRemained();
		timerWidgetPtr->setTimeRemained(timeInSeconds);
	}
}

void ASeedBedItem::OnBeginInteract(IInteractor* playerPtr)
{
	//Create Plant Widget Here
}

void ASeedBedItem::OnInteract(IInteractor* playerPtr)
{
	Super::OnInteract(playerPtr);

	if (!selectorWidgetClass)
		return;

	USeedbedSelectorWidget* selectorWidget = CreateWidget<USeedbedSelectorWidget>(GetWorld(), selectorWidgetClass);
	selectorWidget->AddToViewport(1000);
	selectorWidget->SetVisibility(ESlateVisibility::Visible);
	selectorWidget->setSeedBedOwner(this);

	//While SeedBed Selector not ready
	//if (!plantType) return;
	//plantSlot = Cast<APlant>(GetWorld()->SpawnActor(plantType.Get(), &GetActorTransform()));
	if (!plantSlot)
		return;
}
