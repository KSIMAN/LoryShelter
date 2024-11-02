// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestItem.h"
#include "QuestWidgets/QuestTaskWidget.h"
#include "QuestControlSubsystem.h"
#include "QuestSystemHelper.h"
#include "Kismet/GameplayStatics.h"
#include "LoryShelter/FarmGameInstance.h"


void UQuestItem::addQuestStep(const FText& stepDescr, uint64 actionCounterMax, UQuestObject* objForImpl)
{
	FQuestStep step;
	step.stepText = stepDescr;
	step.doneCounterMax = actionCounterMax;
	questSteps.Push(step);

	if (objForImpl)
		questSteps.Last().bindQuestObject(objForImpl);
}

void FQuestStep::bindQuestObject(UQuestObject* objForImpl)
{
	QuestObject = objForImpl;
	QuestObject->setOwner(this);
	
	UQuestControlSubsystem* QuestSystemPtr = UQuestSystemHelper::GetQuestControlSubsystem(objForImpl->GetWorld());
	if (!QuestSystemPtr)
		return;
	QuestSystemPtr->OnInteractionHappened.AddDynamic(objForImpl, &UQuestObject::OnInteractionNotify);
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
		//viewerPtr->updateStepInfo(stepText, doneCounterCurrent, doneCounterMax);
		viewerPtr->updateStepInfo(*this);
	}
}
