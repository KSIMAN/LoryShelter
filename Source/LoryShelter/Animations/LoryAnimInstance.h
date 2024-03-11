// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LoryAnimInstance.generated.h"


UENUM(BlueprintType)
enum class EMovementType : uint8
{
	DEFAULT,	//Walking
	CARRY,		//Walking with large object in hands
	DRAG		//Walk with drag object by floor(On Future)

};

/**
 * 
 */
UCLASS()
class LORYSHELTER_API ULoryAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	//--Setters----------------------------------------------

	void setMovementType(const EMovementType& type) { movementType = type; };

	//--Getters----------------------------------------------

	EMovementType& getMovementType() { return movementType; };

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMovementType movementType;


};
