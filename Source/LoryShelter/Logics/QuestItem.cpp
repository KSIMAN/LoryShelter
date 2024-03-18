// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestItem.h"

void UQuestItem::addQuestStep(const FText& stepDescr, uint64 actionCounterMax)
{
	TSharedPtr<FQuestStep> step = MakeShared<FQuestStep>();
	if (step.IsValid())
	{
		step->stepText = stepDescr;
		step->doneCounterMax = actionCounterMax;
		questSteps.Push(step.Get());
	}
}
