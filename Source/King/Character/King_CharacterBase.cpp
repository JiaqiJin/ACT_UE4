// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/King_CharacterBase.h"
#include "GAS/King_AbilitySystemComponent.h"

// Sets default values
AKing_CharacterBase::AKing_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKing_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKing_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UAbilitySystemComponent* AKing_CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}