// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "King_PlayerCameraManager.generated.h"

class USkeletalMeshComponent;

UCLASS()
class KING_API AKing_PlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	AKing_PlayerCameraManager();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* CameraBehavior = nullptr;

	UFUNCTION(BlueprintCallable)
	void OnPossess(APawn* aPawn);

	// Helper Function to Update the Camera Anim Instances Variables
	UFUNCTION(BlueprintNativeEvent)
	void UpdateCameraAnimBehaviorBP();

	// Getters
	UFUNCTION(BlueprintPure)
	APawn* GetCameraControlledPawn();

public:
	// Cameras Property
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTransform* PivotTarget = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector* FPTarget = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TP_FOV = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FP_FOV = 0.0f;
protected:
	UPROPERTY()
	APawn* ControlledPawn;
};
