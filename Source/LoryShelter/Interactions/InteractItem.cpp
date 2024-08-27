// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractItem.h"
#include "IInteractor.h"
#include "Kismet/GameplayStatics.h"


#include "../UI/LoryHUD.h" //Bad idea, need to be removed later

// Sets default values
AInteractItem::AInteractItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item Mesh");
	itemCollider = CreateDefaultSubobject<UCapsuleComponent>("Item Interact Collider");
	interactMontage = CreateDefaultSubobject<UAnimMontage>("Interaction Anim Montage");
	interactSound = CreateDefaultSubobject<USoundCue>("Interaction Sound Cue");

	
	itemCollider->SetupAttachment(itemMesh);
}

// Called when the game starts or when spawned
void AInteractItem::BeginPlay()
{
	Super::BeginPlay();
	itemCollider->OnComponentBeginOverlap.AddDynamic(this, &AInteractItem::OnOverlapBegin);
	itemCollider->OnComponentEndOverlap.AddDynamic(this, &AInteractItem::OnOverlapEnd);
	
}

void AInteractItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Handling here, cause overlap event for Item not so often, as for Player Character
	
	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
		OnStartFocus(loryPlayer);
}

void AInteractItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (IInteractor* loryPlayer = Cast<IInteractor>(OtherActor))
		OnEndFocus(loryPlayer);
}

void AInteractItem::OnInteract(IInteractor* playerPtr)
{
	if (!playerPtr)
		return;
	//By default We Watching Item
	//*playerPtr->GetMesh()->GetAnimInstance()->Montage_Play(interactMontage);
	UGameplayStatics::PlaySoundAtLocation(this, interactSound, GetActorLocation());

}

void AInteractItem::OnBeginInteract(IInteractor* playerPtr)
{
	//CreateTimer
	// 
	//if elapsed endInteract
}

void AInteractItem::OnEndInteract(IInteractor* playerPtr)
{
	//if isInteracting
	//Stop Interaction (threadSafe please)
}

void AInteractItem::OnStartFocus(IInteractor* playerPtr)
{
	if (!playerPtr) //*|| //*playerPtr->getFocusItem()) //if focus item != nullptr - object has another interaction
		return;

	bItemCaptured = true;
	//*playerPtr->setFocusItem(this);
	//*playerPtr->getPlayerHUD()->showAliasInteract(itemInfo, static_cast<EAliasIndex>(0));
}

void AInteractItem::OnEndFocus(IInteractor* playerPtr)
{
	if (!playerPtr || !bItemCaptured)
		return;

	bItemCaptured = false;
	//*playerPtr->setFocusItem(nullptr);
	//*playerPtr->getPlayerHUD()->hideAliasInteract(static_cast<EAliasIndex>(0)); //Item intract index = 0
}

void AInteractItem::ToggleItemUsed(const FText& itemUsedAlias, const FText& itemNotUsedAlias)
{
	bItemUsed = !bItemUsed;
	if (bItemUsed)
		itemInfo.interactAlias = itemUsedAlias;
	else
		itemInfo.interactAlias = itemNotUsedAlias;
}


// Called every frame
void AInteractItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

