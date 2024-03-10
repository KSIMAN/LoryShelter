// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/InteractionInterface.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "InteractItem.generated.h"


USTRUCT(BlueprintType)
struct FInteractionInfo
{
	GENERATED_USTRUCT_BODY()

	//Item name
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FName itemName;

	//Alias to show before interacting
	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FString interactAlias;

	UPROPERTY(EditDefaultsOnly, Category = "Item Info")
	FString interactKey;

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


	virtual void beginFocus(ALoryShelterCharacter* playerPtr);

	virtual void endFocus(ALoryShelterCharacter* playerPtr);

	//--SubObjects-----------------------------------------------------------------------------------------------
	
	//Item Mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* itemMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* itemCollider;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UAnimMontage* interactMontage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FInteractionInfo itemInfo;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
