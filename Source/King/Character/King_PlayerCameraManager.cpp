// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/King_PlayerCameraManager.h"
#include "Components/SkeletalMeshComponent.h"

AKing_PlayerCameraManager::AKing_PlayerCameraManager()
{
	CameraBehavior = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CameraBehavior"));
	CameraBehavior->SetupAttachment(GetTransformComponent());
}