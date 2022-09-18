// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify/State/King_ComboCheckAnimNotify.h"
#include "Interface/King_CombatInterface.h"
#include "King_Types.h"

void UKing_ComboCheckAnimNotify::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	if (IKing_CombatInterface* InCharacter = Cast<IKing_CombatInterface>(MeshComp->GetOuter()))
	{
		InCharacter->GetSimpleCombatInfo()->bShortPress = false;
		InCharacter->GetSimpleCombatInfo()->UpdateCombatIndex();
	}

}

void UKing_ComboCheckAnimNotify::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UKing_ComboCheckAnimNotify::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	if (IKing_CombatInterface* InCharacter = Cast<IKing_CombatInterface>(MeshComp->GetOuter()))
	{
		if ((InCharacter->GetSimpleCombatInfo()->bLongPress || InCharacter->GetSimpleCombatInfo()->bShortPress))
		{
			// Jump Section
		}
	}
}
