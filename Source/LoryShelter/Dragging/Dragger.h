// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Dragger.generated.h"

USTRUCT()
struct FDragInfo
{
	GENERATED_USTRUCT_BODY()
	FVector AttachmentPoint;
	FRotator AttachmentRotator;
	TObjectPtr<ACharacter> AttachmentActor;
	bool bToSocket;
	FName SocketName;
};

// This class does not need to be modified.
UINTERFACE()
class UDragger : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class IDraggable;

class LORYSHELTER_API IDragger
{
	GENERATED_BODY()

public:
	//Dragger Puts Up Item
	virtual uint8 PutUp(IDraggable*) = 0;
	//Dragger Puts Down Item
	virtual uint8 PutDown(IDraggable*) = 0;

	virtual FVector GetPutDownPoint() = 0;

	virtual FDragInfo GetDragInfo() = 0;

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
};
