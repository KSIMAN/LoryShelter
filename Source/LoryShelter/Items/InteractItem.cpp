// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractItem.h"
#include "../LoryShelterCharacter.h"
#include "../UI/LoryHUD.h" //Bad idea, need to be removed later

// Sets default values
AInteractItem::AInteractItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	itemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item Mesh");
	itemCollider = CreateDefaultSubobject<UCapsuleComponent>("Item Interact Collider");

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
	
	if (ALoryShelterCharacter* loryPlayer = Cast<ALoryShelterCharacter>(OtherActor))
		beginFocus(loryPlayer);
}

void AInteractItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ALoryShelterCharacter* loryPlayer = Cast<ALoryShelterCharacter>(OtherActor))
		endFocus(loryPlayer);
}

void AInteractItem::beginFocus(ALoryShelterCharacter* playerPtr)
{
	playerPtr->getPlayerHUD()->showAliasInteract(itemInfo);
}

void AInteractItem::endFocus(ALoryShelterCharacter* playerPtr)
{
	playerPtr->getPlayerHUD()->hideAliasInteract();
}

// Called every frame
void AInteractItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

