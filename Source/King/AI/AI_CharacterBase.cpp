// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI_CharacterBase.h"
#include "GAS/King_AttributeSet.h"
#include "GAS/King_AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "GameFramework/Controller.h"
#include "AIController.h"
#include "Datas/GameplayAbilityDatas/King_GameplayAbilityDatas.h"

// Sets default values
AAI_CharacterBase::AAI_CharacterBase(const class FObjectInitializer& InitializerObject)
	: Super(InitializerObject)
{
	PlayerAttributes = CreateDefaultSubobject<UKing_AttributeSet>(TEXT("AttributeSetBase"));
	AbilitySystemComponent = CreateDefaultSubobject<UKing_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AAI_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAI_CharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitializeAttributes();
	GrantAICharacterAbilities();
}

void AAI_CharacterBase::InitializeAttributes()
{
	if (!AbilitySystemComponent.IsValid())
	{
		return;
	}

	if (!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the character's Blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}

	// Can run on Server and Client
	FGameplayEffectContextHandle AI_EffectContext = AbilitySystemComponent->MakeEffectContext();
	AI_EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, AI_EffectContext);
	if (NewHandle.IsValid())
	{
		// Apply Attribute GameplayEffect
		FActiveGameplayEffectHandle ActiveGEHandle = 
			AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent.Get());
	}
}

// Grant Ability to AI
void AAI_CharacterBase::GrantAICharacterAbilities()
{
	// Grant abilities, but only on the server	
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid())
	{
		return;
	}

	if (!DefaultAbilityDatas)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAbilityDatas for %s. Please fill in the character's Blueprint."), 
			*FString(__FUNCTION__), *GetName());
		return;
	}

	for (FKingGameplayAbilityInfo Ability : DefaultAbilityDatas->Abilities)
	{
		if (!Ability.Ability)
		{
			UE_LOG(LogTemp, Error, TEXT("%s() Ability Not Granted for %s. Ability is not valid."), *FString(__FUNCTION__), *GetName());
			return;
		}

		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability.Ability, 1, static_cast<uint32>(Ability.AbilityKeys), this));
	}
}
