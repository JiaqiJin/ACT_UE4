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
};
