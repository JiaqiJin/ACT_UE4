// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/King_PlayerController.h"

AKing_PlayerController::AKing_PlayerController(const class FObjectInitializer& InitializerObject)
	: Super(InitializerObject)
{

}

// Called when the game starts
void AKing_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AKing_PlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
}