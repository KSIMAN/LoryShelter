// Copyright Epic Games, Inc. All Rights Reserved.

#include "LoryShelterGameMode.h"
#include "LoryShelterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALoryShelterGameMode::ALoryShelterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
