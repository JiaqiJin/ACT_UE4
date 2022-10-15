// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Abilities/King_DashAbility.h"
#include "KingCharacter.h"
#include "GAS/AbilityTasks/King_PlayMontageAndWaitEvent.h"
#include "AbilitySystemComponent.h"
#include "Character/King_CharacterBase.h"

UKing_DashAbility::UKing_DashAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	bIsCreateOnRunning = GIsRunning;
}

void UKing_DashAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	if (!IsValid(AnimMontageDashForward) || !IsValid(AnimMontageDashBackwards) || !IsValid(AnimMontageDashRight) || !IsValid(AnimMontageDashLeft))
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] UKing_DashAbility: Cannot get Animation Montage ... "), *GetName());
		Super::EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	Character = Cast<AKing_CharacterBase>(GetAvatarActorFromActorInfo());
	if (!Character)
	{
		UE_LOG(LogTemp, Display, TEXT("[%s] UKing_DashAbility: Cannot Cast ASATORICharacter ... "), *GetName());
		Super::EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		UE_LOG(LogTemp, Display, TEXT("[%s] UKing_DashAbility: Failed commit ability ... "), *GetName());
		Super::EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		return;
	}

	CollisionParams.AddIgnoredActor(GetAvatarActorFromActorInfo());

	if (!Character->GetVelocity().IsNearlyZero(0.0001f))
	{
		CharacterForwardVector = Character->GetActorForwardVector();
		CharacterRightVector = Character->GetActorRightVector();
		VelocityVector = Character->GetVelocity();
		VelocityVector.Normalize(0.0001f);
	}

	float ForwardResult = FVector::DotProduct(CharacterForwardVector, VelocityVector);
	float RightResult = FVector::DotProduct(CharacterRightVector, VelocityVector);

	if (FMath::IsNearlyEqual(ForwardResult, 1.0f, 0.025f))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Up !!!!");
		UKing_PlayMontageAndWaitEvent* Task = UKing_PlayMontageAndWaitEvent::PlayMontageAndWaitForEvent(this, NAME_None, AnimMontageDashForward, FGameplayTagContainer(), 1.0f, NAME_None, bStopWhenAbilityEnds, 1.0f);
		Task->OnBlendOut.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnCompleted.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnInterrupted.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->OnCancelled.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->EventReceived.AddDynamic(this, &UKing_DashAbility::EventReceived);
		Task->ReadyForActivation();
	}

	else if (FMath::IsNearlyEqual(ForwardResult, -1.0f, 0.025f))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Down !!!!");
		UKing_PlayMontageAndWaitEvent* Task = UKing_PlayMontageAndWaitEvent::PlayMontageAndWaitForEvent(this, NAME_None, AnimMontageDashForward, FGameplayTagContainer(), 1.0f, NAME_None, bStopWhenAbilityEnds, 1.0f);
		Task->OnBlendOut.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnCompleted.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnInterrupted.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->OnCancelled.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->EventReceived.AddDynamic(this, &UKing_DashAbility::EventReceived);
		Task->ReadyForActivation();
	}

	else if (FMath::IsNearlyEqual(RightResult, 1.0f, 0.025f))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Left !!!!");
		UKing_PlayMontageAndWaitEvent* Task = UKing_PlayMontageAndWaitEvent::PlayMontageAndWaitForEvent(this, NAME_None, AnimMontageDashForward, FGameplayTagContainer(), 1.0f, NAME_None, bStopWhenAbilityEnds, 1.0f);
		Task->OnBlendOut.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnCompleted.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnInterrupted.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->OnCancelled.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->EventReceived.AddDynamic(this, &UKing_DashAbility::EventReceived);
		Task->ReadyForActivation();
	}

	else if (FMath::IsNearlyEqual(RightResult, -1.0f, 0.025f))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "Rigth !!!!");
		UKing_PlayMontageAndWaitEvent* Task = UKing_PlayMontageAndWaitEvent::PlayMontageAndWaitForEvent(this, NAME_None, AnimMontageDashForward, FGameplayTagContainer(), 1.0f, NAME_None, bStopWhenAbilityEnds, 1.0f);
		Task->OnBlendOut.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnCompleted.AddDynamic(this, &UKing_DashAbility::OnCompleted);
		Task->OnInterrupted.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->OnCancelled.AddDynamic(this, &UKing_DashAbility::OnCancelled);
		Task->EventReceived.AddDynamic(this, &UKing_DashAbility::EventReceived);
		Task->ReadyForActivation();
	}
}

void UKing_DashAbility::EndAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool bReplicateEndAbility,
	bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UKing_DashAbility::OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UKing_DashAbility::OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData)
{
	EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
}

void UKing_DashAbility::EventReceived(FGameplayTag EventTag, FGameplayEventData EventData)
{
	
}
