// Fill out your copyright notice in the Description page of Project Settings.


#include "LoryAnimInstance.h"

void ULoryAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	velocity = GetOwningActor()->GetVelocity().Length();
}
