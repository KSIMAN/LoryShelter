// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/InteractionInterface.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Sound/SoundCue.h"
#include "InteractItem.generated.h"


USTRUCT(BlueprintType)
struct FInteractionInfo
{
	GENERATED_USTRUCT_BODY()

	//Item name
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText itemName;

	//Alias to show before interacting
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText interactAlias;

	//Key For Interaction. Maybe Deprecated
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FText interactKey;

	//Duration of interaction in seconds
	int interactDuration;

};

UCLASS()
class LORYSHELTER_API AInteractItem : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractItem();

	//--Getters----------------------------------------
	// 
	//returns AnimMontage for Interaction
	UAnimMontage* getInteractMontage() { return interactMontage; };

	UStaticMeshComponent* getMesh() { return itemMesh; };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Begin Overlap Delegate
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//End Overlap Delegate
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	//--Interaction Interface------------------------------------------------------------------------------------

	virtual void Interact(ALoryShelterCharacter* playerPtr)override;

	virtual void beginInteract(ALoryShelterCharacter* playerPtr) override;

	virtual void endInteract(ALoryShelterCharacter* playerPtr) override;

	virtual void beginFocus(ALoryShelterCharacter* playerPtr) override;

	virtual void endFocus(ALoryShelterCharacter* playerPtr) override;

	//--SubObjects-----------------------------------------------------------------------------------------------
	
	//Item Mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* itemMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* itemCollider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInteractionInfo itemInfo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Content")
	UAnimMontage* interactMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Content")
	USoundCue* interactSound;





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
