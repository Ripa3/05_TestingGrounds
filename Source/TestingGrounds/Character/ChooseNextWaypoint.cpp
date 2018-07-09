// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolComponent.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//get patrol points
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolComponent = ControlledPawn->FindComponentByClass<UPatrolComponent>();

	if (!ensure(PatrolComponent)) { return EBTNodeResult::Failed; }

	auto PatrolPoints = PatrolComponent->GetPatrolPoints();

	if (ensure(PatrolPoints.Num() != 0))
	{
		//set nextwaypoint
		auto BlackboardComp = OwnerComp.GetBlackboardComponent();
		auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
		BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

		//cycle index
		auto NextIndex = (Index + 1) % PatrolPoints.Num();
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

		return EBTNodeResult::Succeeded;
	}

	else return EBTNodeResult::Failed;
}
