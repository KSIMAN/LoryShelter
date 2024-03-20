// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestItem.h"
#include "NotifyDispatcher.h"


void UQuestItem::addQuestStep(const FText& stepDescr, uint64 actionCounterMax, UQuestObject* objForImpl)
{
	TSharedPtr<FQuestStep> step = MakeShared<FQuestStep>();
	if (step.IsValid())
	{
		step->stepText = stepDescr;
		step->doneCounterMax = actionCounterMax;
		questSteps.Push(step.ToWeakPtr());

		if (objForImpl)
			step->bindQuestObject(objForImpl);
	}
}

void FQuestStep::bindQuestObject(UQuestObject* objForImpl)
{
	objForImpl->setOwner(this);
	UNotifyDispatcher::getNotifyDispatcherInstance()->OnInteractionHappened.AddDynamic(objForImpl, &UQuestObject::OnInteractionNotify);
}

void FQuestStep::stepUnitDone()
{
	if (doneCounterCurrent < doneCounterMax)
		doneCounterCurrent++;


}
