// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/King_PlayerCameraManager.h"
#include "Components/SkeletalMeshComponent.h"

AKing_PlayerCameraManager::AKing_PlayerCameraManager()
{
	CameraBehavior = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CameraBehavior"));
	CameraBehavior->SetupAttachment(GetTransformComponent());
}

void AKing_PlayerCameraManager::OnPossess(APawn* aPawn)
{
	ControlledPawn = aPawn;

	if (!ControlledPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Empty APawn Class."),
			*FString(__FUNCTION__), *GetName());
		return;
	}

	UpdateCameraAnimBehaviorBP();
}

void AKing_PlayerCameraManager::UpdateCameraAnimBehaviorBP_Implementation()
{

}

APawn* AKing_PlayerCameraManager::GetCameraControlledPawn()
{
	if (ControlledPawn)
	{
		return ControlledPawn;
	}

	return nullptr;
}