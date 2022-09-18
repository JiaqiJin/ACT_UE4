// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/Player/King_CombatComponent.h"
#include "GAS/King_AbilitySystemComponent.h"
#include "GAS/King_GameplayAbility.h"
#include "KingCharacter.h"

// Sets default values for this component's properties
UKing_CombatComponent::UKing_CombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKing_CombatComponent::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AKingCharacter>(GetOwner());
	
	RegisterCombatAttack(CombatAttack, TEXT("NormalAttack"));
}

void UKing_CombatComponent::NormalAttack(const FName& InKey)
{

}

void UKing_CombatComponent::RegisterCombatAttack(FSimpleCombatCheck& InCombatCheck, const FName& InKey)
{
	InCombatCheck.Character = Character.Get();
	InCombatCheck.CombatKey = InKey;
	InCombatCheck.MaxIndex = 4;
}