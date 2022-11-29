// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/King_CharacterBase.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AI_CharacterBase.generated.h"

class UKing_AbilitySystemComponent;

UCLASS()
class KING_API AAI_CharacterBase : public AKing_CharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_CharacterBase(const class FObjectInitializer& InitializerObject);

	virtual void PossessedBy(AController* NewController) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	// The core ActorComponent for interfacing with the GameplayAbilities System
	TWeakObjectPtr<UKing_AbilitySystemComponent> AbilitySystemComponent;
};
