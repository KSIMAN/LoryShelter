// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Dragging/Dragger.h"
#include "GameFramework/Character.h"
#include "Interactions/IInteractable.h"
#include "Interactions/IInteractor.h"
#include "Logging/LogMacros.h"
#include "Sitting/Sitter.h"
#include "LoryShelterCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ALoryHUD;
class UQuestSystemComponent;


DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ALoryShelterCharacter : public ACharacter, public IInteractor, public ISitter, public IDragger
{
	GENERATED_BODY()

	//--Engine Defaults-----------------------------------------------

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	//Custom Anim Instance Ptr
	class ULoryAnimInstance* animInstance;

	//--Interaction Interface------------------------------------------------------------------------

	//Player is near item and can begin interact if he wants
	virtual void StartFocus(IInteractable* itemPtr) override;

	//Player not near item yet. 
	virtual void EndFocus(IInteractable* itemPtr) override;

	//Player begin interaction
	virtual void BeginInteract(IInteractable* itemPtr) override;

	//Interaction is over
	virtual void EndInteract(IInteractable* itemPtr) override;

	//Interaction process
	virtual void Interact(IInteractable* itemPtr) override;

	virtual IInteractable* GetFocusItem() override { return interactionItem; } ;
	//Setting up Pointer on Item, that can be Interacted
	virtual void SetFocusItem(IInteractable* itemPointer) override;

	IInteractable* interactionItem;

	//--Sitting Interface------------------------------------------------------------------------

	virtual uint8 SitDown(ISittable* item) override;
	virtual uint8 SitUp(ISittable* item) override;

	//--UI Components--------------------------------------------------------------------------------

	//Base HUD for player
	UPROPERTY()
	ALoryHUD* baseHUD;

	//--Custom Delegates-----------------------------------------------------------------------------
	UFUNCTION()
	void OnAnimMontageEnded(UAnimMontage* Montage, bool bInterrupted);
	UFUNCTION()
	void OnAnimMontageStarted(UAnimMontage* Montage);

protected:
	//--Components-----------------------------------------------------------------------------------

	//Quest Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UQuestSystemComponent* questSystemComp;

	//--Variables-------------------------------------------------------------------------------------

	//true if Player Can't Move
	bool bMovementBlock;

	//--User Input------------------------------------------------------------------------------------

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// To add mapping context
	virtual void BeginPlay() override;

	void InteractAction();

public:
	//Default Constructor
	ALoryShelterCharacter();

	//--Actions Logic Callbacks-----------------------------------------------------------------------

	//Dragger Puts Up Item
	virtual uint8 PutUp(IDraggable*) override;
	//Dragger Puts Down Item
	virtual uint8 PutDown(IDraggable*) override;
	//
	virtual FVector GetPutDownPoint() override;

	virtual FDragInfo GetDragInfo() override;
	// //Picks Up Item To drag return state 
	// uint8 pickUpForDragging(AActor* item);
	//
	// //Puts Down Item  return state 
	// uint8 putDownItem(AActor* item);

	//--Setters------------------------------------------------------------------------


	//--Getters------------------------------------------------------------------------

	//Returns LoryHud pointer
	ALoryHUD* getPlayerHUD() const { return baseHUD; };


	// Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Returns FollowCamera subobject 
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
