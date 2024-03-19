// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Items/InteractItem.h"
#include "QuestSystemComponent.generated.h"

class UQuestItem;
class UQuestPanel;
class ALoryShelterCharacter; //On Future


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LORYSHELTER_API UQuestSystemComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UQuestSystemComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//--Getters--------------------------

	//Returns Quest Panel Pointer
	UQuestPanel* getQuestPanel() const { return questPanel; };

	//Inits Quest Panel UI For Player Controller
	void initQuestPanel();
	
	//Add Quest To Player
	void addQuest(UQuestItem* questItem);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Quest Panel Widget SubClass
	UPROPERTY(EditAnywhere)
	TSubclassOf<UQuestPanel> questPanelClass;

	//Quests Array
	TArray<UQuestItem*> quests;

	//Quest Panel Pointer
	UQuestPanel* questPanel;

};
