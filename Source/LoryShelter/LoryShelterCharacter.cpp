// Copyright Epic Games, Inc. All Rights Reserved.

#include "LoryShelterCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Logics/QuestSystemComponent.h" //Move To Components Folder Please
#include "Logics/QuestItem.h"
#include "UI/LoryHUD.h"
#include "Animations/LoryAnimInstance.h"
#include "Engine/SkeletalMeshSocket.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ALoryShelterCharacter


ALoryShelterCharacter::ALoryShelterCharacter() : interactionItem(nullptr), bMovementBlock(false)
{
	//Engine Defaults
	{
		// Set size for collision capsule
		GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

		// Don't rotate when the controller rotates. Let that just affect the camera.
		bUseControllerRotationPitch = false;
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false;

		// Configure character movement
		GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

		// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
		// instead of recompiling to adjust them
		GetCharacterMovement()->JumpZVelocity = 700.f;
		GetCharacterMovement()->AirControl = 0.35f;
		GetCharacterMovement()->MaxWalkSpeed = 500.f;
		GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
		GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
		GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

		// Create a camera boom (pulls in towards the player if there is a collision)
		CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
		CameraBoom->SetupAttachment(RootComponent);
		CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
		CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

		// Create a follow camera
		FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
		FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
		FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

		// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
		// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
	}
	
	questSystemComp = CreateDefaultSubobject<UQuestSystemComponent>("Quest System Component");

}

void ALoryShelterCharacter::setFocusItem(IInteractionInterface* itemPointer)
{
	if (interactionItem && itemPointer) //if has focus item 
		return;
	interactionItem = itemPointer; //We don't mind if its nullptr
}

void ALoryShelterCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}

		baseHUD = Cast<ALoryHUD>(PlayerController->GetHUD());
		
	}

	//////////////////////////////////////////////
	// Move to Quests desc and parse from json
	UQuestItem* testQuest = NewObject<UQuestItem>(this);
	testQuest->questName = FName("Fluffy escape");
	testQuest->questDecr = FText(FText::FromString(TEXT("Return escaped rabbits to the aviary")));
	questSystemComp->addQuest(testQuest);

	UQuestItem* testQuest2 = NewObject<UQuestItem>(this);
	testQuest->questName = FName("Barn work");
	testQuest->questDecr = FText(FText::FromString(TEXT("Load sacks of flour form the barn into the truck at the entrance")));
	questSystemComp->addQuest(testQuest2);

	GetMesh()->GetAnimInstance()->OnMontageStarted.AddDynamic(this, &ALoryShelterCharacter::OnAnimMontageStarted);
	GetMesh()->GetAnimInstance()->OnMontageEnded.AddDynamic(this, &ALoryShelterCharacter::OnAnimMontageEnded);
	
	animInstance = Cast<ULoryAnimInstance>(GetMesh()->GetAnimInstance());

}


//////////////////////////////////////////////////////////////////////////
// Input

void ALoryShelterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings

	PlayerInputComponent->BindAction("Interaction", EInputEvent::IE_Pressed, this, &ALoryShelterCharacter::BeginInteractItem);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ALoryShelterCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ALoryShelterCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ALoryShelterCharacter::OnAnimMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	bMovementBlock = false;
}

void ALoryShelterCharacter::OnAnimMontageStarted(UAnimMontage* Montage)
{
	bMovementBlock = true;
}

uint8 ALoryShelterCharacter::pickUpForDragging(AActor* item)
{
	if (!animInstance)
		return -1;

	animInstance->setMovementType(EMovementType::CARRY);

	//Move to class Members later
	const USkeletalMeshSocket* rhSocket = GetMesh()->GetSocketByName(FName("RHSocket"));
	const USkeletalMeshSocket* lhSocket = GetMesh()->GetSocketByName(FName("LHSocket"));

	if (!rhSocket || !lhSocket)
		return -1;

	FVector lhLoc = lhSocket->GetSocketLocation(GetMesh()); 
	FVector rhLoc = rhSocket->GetSocketLocation(GetMesh());

	FVector betwHandsLoc = lhLoc + GetActorRightVector() * FVector::DistXY(rhLoc, rhLoc) / 2; //Center Location between hands
	item->SetActorLocation(betwHandsLoc);
	item->SetActorRotation(GetControlRotation());
	item->AttachToComponent(this->GetMesh(), FAttachmentTransformRules::KeepWorldTransform, FName("RHSocket"));
	//Change Actor Location
	//item->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	return 0;
}

uint8 ALoryShelterCharacter::putDownItem(AActor* item)
{
	if (!animInstance)
		return -1;

	//Find point  to put down
	FVector groundPoint;

	float putDistance = 5;
	float bottomMax = 100;

	FVector vTraceStart{ GetActorLocation() + GetActorForwardVector() * putDistance };
	FVector vTraceEnd{ vTraceStart - FVector(0,0, bottomMax)};

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	FHitResult traceHit;

	if (GetWorld()->LineTraceSingleByChannel(traceHit, vTraceStart, vTraceEnd, ECollisionChannel::ECC_Visibility, queryParams))
	{
		groundPoint = traceHit.ImpactPoint;
	}
	else
		return -1;

	animInstance->setMovementType(EMovementType::DEFAULT);
	//Change Actor Location
	item->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	//Change actor location
	item->SetActorLocation(groundPoint);

	return 0;
}

uint8 ALoryShelterCharacter::sitDownToItem(const FVector& sittingPoint)
{
	if (!animInstance)
		return -1;

	SetActorLocation(sittingPoint);
	bMovementBlock = true;
	animInstance->setMovementType(EMovementType::SITTING);
	return 0;

}

uint8 ALoryShelterCharacter::sitUpFromItem()
{
	if (!animInstance)
		return -1;

	//Find point  to put down remove dubbles later
	FVector groundPoint;

	float putDistance = 20;
	float bottomMax = 100;

	FVector vTraceStart{ GetActorLocation() + GetActorForwardVector() * putDistance };
	FVector vTraceEnd{ vTraceStart - FVector(0,0, bottomMax) };

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(this);
	FHitResult traceHit;

	if (GetWorld()->LineTraceSingleByChannel(traceHit, vTraceStart, vTraceEnd, ECollisionChannel::ECC_Visibility, queryParams))
	{
		groundPoint = traceHit.ImpactPoint;
	}
	else
		return -1;

	SetActorLocation(groundPoint);
	bMovementBlock = false;
	animInstance->setMovementType(EMovementType::DEFAULT);

	return 0;
}

void ALoryShelterCharacter::Move(const FInputActionValue& Value)
{
	if (bMovementBlock) return; //Need To Check Where Is Using bBlockInput in Pawn

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ALoryShelterCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ALoryShelterCharacter::BeginInteractItem()
{
	if (!interactionItem)
		return; //Nothing to Interact With

	//interactionItem->beginInteract(this); (on future)
	interactionItem->Interact(this);
}
