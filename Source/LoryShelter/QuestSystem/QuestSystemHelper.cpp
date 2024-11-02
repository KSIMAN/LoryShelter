// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystemHelper.h"

UQuestControlSubsystem* UQuestSystemHelper::GetQuestControlSubsystem(UWorld* World)
{
	UGameInstance* GameInstance = World->GetGameInstance();

	if (!GameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wrong game instance for quests"));
		return nullptr;
	}
	UQuestControlSubsystem* QuestSystemPtr = GameInstance->GetSubsystem<UQuestControlSubsystem>();
	if(!QuestSystemPtr)
		UE_LOG(LogTemp, Warning, TEXT("Wrong subsytem in game instance for quests"));
	
	return QuestSystemPtr;
}
