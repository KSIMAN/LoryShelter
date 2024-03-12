// Copyright Epic Games, Inc. All Rights Reserved.

#include "LoryShelter.h"
#include "Modules/ModuleManager.h"

#include "Internationalization/StringTableRegistry.h"

void FLoryShelter::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	//--Loading String Tables here----------------------------------------------------

	LOCTABLE_FROMFILE_GAME("ItemsST", "ItemsST", "Localization/ItemsST.csv");
	LOCTABLE_FROMFILE_GAME("ActionsST", "ActionsST", "Localization/ActionsST.csv");
	LOCTABLE_FROMFILE_GAME("GameplayST", "GameplayST", "Localization/GameplayST.csv");
}

void FLoryShelter::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();
}


IMPLEMENT_PRIMARY_GAME_MODULE(FLoryShelter, LoryShelter, "LoryShelter" );

