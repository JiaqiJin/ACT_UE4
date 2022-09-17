// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "King_PlayerAbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KING_API UKing_PlayerAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKing_PlayerAbilityComponent();

	void LoadAllGameplayAbilities();
	void LoadGameplayAbilities(class UKing_GameplayAbilityDatas* Datas);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
