// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestItem.h"
#include "../UI/QuestWidgets/QuestTaskWidget.h"
#include "NotifyDispatcher.h"


void UQuestItem::addQuestStep(const FText& stepDescr, uint64 actionCounterMax, UQuestObject* objForImpl)
{
	TSharedPtr<FQuestStep> step = MakeShared<FQuestStep>();
	if (step.IsValid())
	{
		step->stepText = stepDescr;
		step->doneCounterMax = actionCounterMax;
		questSteps.Push(step.ToSharedRef());

		if (objForImpl)
			step->bindQuestObject(objForImpl);
	}
}

void FQuestStep::bindQuestObject(UQuestObject* objForImpl)
{
	questImpl = objForImpl;
	questImpl->setOwner(this);

	UNotifyDispatcher::getNotifyDispatcherInstance()->OnInteractionHappened.AddDynamic(objForImpl, &UQuestObject::OnInteractionNotify);
}

void FQuestStep::setTaskViewerRef(UQuestTaskWidget* viewerWidget)
{
	viewerPtr = viewerWidget;
}

void FQuestStep::stepUnitDone()
{
	if (doneCounterCurrent < doneCounterMax)
		doneCounterCurrent++;
	else
	{
		//Unit done event
	}

	//Update UI info
	if (viewerPtr)
	{
		viewerPtr->updateStepInfo(*this);
	}
}
