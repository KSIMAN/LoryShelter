// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/InteractionInterface.h"
#include "Logging/LogMacros.h"
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
class ALoryShelterCharacter : public ACharacter
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

	IInteractionInterface* interactionItem;

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

	//Called when user press Interaction Key
	void BeginInteractItem();

	//Called when user unpress Interaction Key (on future)
	//void BeginInteractItem();

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	// To add mapping context
	virtual void BeginPlay();

public:
	//Default Constructor
	ALoryShelterCharacter();

	//--Actions Logic Callbacks-----------------------------------------------------------------------

	//Picks Up Item To drag return state 
	uint8 pickUpForDragging(AActor* item);

	//Puts Down Item  return state 
	uint8 putDownItem(AActor* item);
	
	//Sitting Down
	uint8 sitDownToItem(const FVector& sittingPoint);

	//Sitting Up
	uint8 sitUpFromItem();

	//--Setters------------------------------------------------------------------------

	//Setting up Pointer on Item, that can be Interacted
	void setFocusItem(IInteractionInterface* itemPointer);


	//--Getters------------------------------------------------------------------------

	//Returns LoryHud pointer
	ALoryHUD* getPlayerHUD() const { return baseHUD; };

	// Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Returns FollowCamera subobject 
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

