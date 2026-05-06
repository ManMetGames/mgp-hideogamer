// Copyright Epic Games, Inc. All Rights Reserved.

#include "UniGDEVMechanicCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UniGDEVMechanic.h"
#include "CableComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework//CharacterMovementComponent.h"

AUniGDEVMechanicCharacter::AUniGDEVMechanicCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(FirstPersonMesh, FName("head"));
	FirstPersonCameraComponent->SetRelativeLocationAndRotation(FVector(-2.8f, 5.89f, 0.0f), FRotator(0.0f, 90.0f, -90.0f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	// configure the character comps
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCapsuleComponent()->SetCapsuleSize(34.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	GrappleCable = CreateDefaultSubobject<UCableComponent>(TEXT("Grappling Line"));
	GrappleCable->SetupAttachment(FirstPersonCameraComponent);
	GrappleCable->SetVisibility(false);
}

void AUniGDEVMechanicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AUniGDEVMechanicCharacter::DoJumpStart);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AUniGDEVMechanicCharacter::DoJumpEnd);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUniGDEVMechanicCharacter::MoveInput);

		// Looking/Aiming
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUniGDEVMechanicCharacter::LookInput);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AUniGDEVMechanicCharacter::LookInput);

		// Grappling
		EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Triggered, this, &AUniGDEVMechanicCharacter::Grapple);
		EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Completed, this, &AUniGDEVMechanicCharacter::StopGrapple);



	}
	else
	{
		UE_LOG(LogUniGDEVMechanic, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AUniGDEVMechanicCharacter::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (isGrappling) 
	{
		// Get the end location using the grapple point transform
		GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(GrapplePoint);

		// Move Player towards the grapple point
		GetCharacterMovement()->AddForce((GrapplePoint - GetActorLocation()).GetSafeNormal() * 100000);
	}
}

void AUniGDEVMechanicCharacter::Grapple()
{
	// Get Capsule Component location
	FVector Start = GetCapsuleComponent()->GetComponentLocation();
	//Line trace of the grapple. Distance and direction.
	FVector End = Start + (MaxGrappleDistance * UKismetMathLibrary::GetForwardVector(FirstPersonCameraComponent->GetComponentRotation()));
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	FHitResult HitResult;

	// Populate HitResult with the first collision in the Grappleable trace channel. hasHit is true if there is any collision
	bool hasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, FCollisionShape::MakeSphere(100.f));

	if (hasHit) 
	{
		isGrappling = true;
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		GrappleCable->SetVisibility(true);
		GrapplePoint = HitResult.ImpactPoint;
	}
}

void AUniGDEVMechanicCharacter::StopGrapple()
{
	isGrappling = false;
	if (!GetCharacterMovement()->IsFalling()) 
	{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
	}
	GrappleCable->SetVisibility(false);
}


void AUniGDEVMechanicCharacter::MoveInput(const FInputActionValue& Value)
{
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);

}

void AUniGDEVMechanicCharacter::LookInput(const FInputActionValue& Value)
{
	// get the Vector2D look axis
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// pass the axis values to the aim input
	DoAim(LookAxisVector.X, LookAxisVector.Y);

}

void AUniGDEVMechanicCharacter::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		// pass the rotation inputs
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void AUniGDEVMechanicCharacter::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		// pass the move inputs
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void AUniGDEVMechanicCharacter::DoJumpStart()
{
	// pass Jump to the character
	Jump();
}

void AUniGDEVMechanicCharacter::DoJumpEnd()
{
	// pass StopJumping to the character
	StopJumping();
}
