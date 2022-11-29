// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_CharacterBase.h"

// Sets default values
AAI_CharacterBase::AAI_CharacterBase(const class FObjectInitializer& InitializerObject)
	: Super(InitializerObject)
{
 	
}

// Called when the game starts or when spawned
void AAI_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_CharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

