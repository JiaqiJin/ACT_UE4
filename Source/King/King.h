// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
namespace EKingAbilityInputID
{
	enum Type
	{
		// 0 None
		None			UMETA(DisplayName = "None"),
		// 1 Confirm
		Confirm			UMETA(DisplayName = "Confirm"),
		// 2 Cancel
		Cancel			UMETA(DisplayName = "Cancel"),
		// Dash
		Dash			UMETA(DisplayName = "Dash"),
		// Attack
		Attack			UMETA(DisplayName = "Attack"),
	};
}