// Copyright Epic Games, Inc. All Rights Reserved.

#include "KingCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "GAS/King_AbilitySystemComponent.h"
#include "King.h"
#include "Component/Player/King_PlayerAbilityComponent.h"
#include "Component/Player/King_CombatComponent.h"
#include "King_Types.h"

//////////////////////////////////////////////////////////////////////////
// AKingCharacter

AKingCharacter::AKingCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Component
	AbilitySystemComponent = CreateDefaultSubobject<UKing_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	PlayerAbilityComponent = CreateDefaultSubobject<UKing_PlayerAbilityComponent>(TEXT("PlayerAbilityComponent"));
	CombatComponent = CreateDefaultSubobject<UKing_CombatComponent>(TEXT("CombatComponent"));
	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void AKingCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AKingCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerAbilityComponent->LoadAllGameplayAbilities();
}

void AKingCharacter::CombatAttack(const FName& InKey)
{
	NormalAttack(InKey);
}

void AKingCharacter::NormalAttack(const FName& InKey)
{
	CombatComponent->NormalAttack(InKey);
}

FSimpleCombatCheck* AKingCharacter::GetSimpleCombatInfo()
{
	return CombatComponent->GetSimpleCombatInfo();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AKingCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AKingCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AKingCharacter::MoveRight);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AKingCharacter::MouseLeftClick);
	PlayerInputComponent->BindAction("AttackReleased", IE_Released, this, &AKingCharacter::MouseLeftClickReleased);
	PlayerInputComponent->BindAction("HeavyAttack", IE_Pressed, this, &AKingCharacter::MouseRightClick);
	PlayerInputComponent->BindAction("HeavyAttackReleased", IE_Released, this, &AKingCharacter::MouseRightClickReleased);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AKingCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AKingCharacter::LookUpAtRate);

	AbilitySystemComponent->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds(FString("ConfirmTarget"),
		FString("CancelTarget"), FString("EKingAbilityInputID"), static_cast<int32>(EKingAbilityInputID::Type::Confirm), static_cast<int32>(EKingAbilityInputID::Type::Cancel)));
}

void AKingCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AKingCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AKingCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AKingCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AKingCharacter::MouseLeftClick()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("MouseLeftClick"));
	GetSimpleCombatInfo()->Press();
}

void AKingCharacter::MouseRightClick()
{

}

void AKingCharacter::MouseLeftClickReleased()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("MouseLeftClickReleased"));
	GetSimpleCombatInfo()->Released();
}

void AKingCharacter::MouseRightClickReleased()
{

}