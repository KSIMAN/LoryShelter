// Fill out your copyright notice in the Description page of Project Settings.


#include "IInteractable.h"

// Add default functionality here for any IInteractionInterface functions that are not pure virtual.


void IInteractable::OnStartFocus(IInteractor* playerPtr)
{
	//When player is near
}

void IInteractable::OnEndFocus(IInteractor* playerPtr)
{
	//When player not near yet
}

void IInteractable::OnBeginInteract(IInteractor* playerPtr)
{
	//SetTimer Here
}

void IInteractable::OnEndInteract(IInteractor* playerPtr)
{
	//Call when Timer Elapsed
}

void IInteractable::OnInteract(IInteractor* playerPtr)
{
}
