// Copyright Epic Games, Inc. All Rights Reserved.

#include "INKINGGameMode.h"
#include "INKINGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AINKINGGameMode::AINKINGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
