// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	auto ControlledPawn = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	if (ControlledPawn) 
	{
		BlackboardComp->SetValueAsObject(NextWaypointKey.SelectedKeyName, ControlledPawn->PatrolPointsCPP[Index]);
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % sizeof(ControlledPawn->PatrolPointsCPP));
	}

	return EBTNodeResult::Succeeded;
}


