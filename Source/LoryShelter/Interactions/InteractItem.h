// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Sound/SoundCue.h"
#include "InteractItem.generated.h"


UCLASS()
class LORYSHELTER_API AInteractItem : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractItem();

	virtual ~AInteractItem() override
	{
	};
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
	                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                    const FHitResult& SweepResult);

	//End Overlap Delegate
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	//--Interaction Interface------------------------------------------------------------------------------------

	//Player is near item and can begin interact if he wants
	virtual void OnStartFocus(IInteractor* playerPtr) override;

	//Player not near item yet. 
	virtual void OnEndFocus(IInteractor* playerPtr) override;

	//Player begin interaction
	virtual void OnBeginInteract(IInteractor* playerPtr) override;

	//Interaction is over
	virtual void OnEndInteract(IInteractor* playerPtr) override;

	//Interaction process
	virtual void OnInteract(IInteractor* playerPtr) override;

	virtual UAnimMontage* GetInteractAnimation() override;

	virtual const FInteractionInfo& GetInteractionInfo() override;

	//Toggle type interaction handler
	virtual void ToggleItemUsed(const FText& itemUsedAlias, const FText& itemNotUsedAlias);

	//--Variables------------------------------------------------------------------------------------------------

	//Indicates that player used this item. Uses for toggle-type interaction
	bool bItemUsed;

	//Info about item for Interaction
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInteractionInfo itemInfo;


	//--SubObjects-----------------------------------------------------------------------------------------------

	//Item Mesh
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* itemMesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UCapsuleComponent* itemCollider;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Content")
	UAnimMontage* interactMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Interaction Content")
	USoundCue* interactSound;

	bool bItemCaptured;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
