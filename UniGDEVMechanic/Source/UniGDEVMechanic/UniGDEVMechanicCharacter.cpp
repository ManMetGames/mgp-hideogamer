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
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Components/PrimitiveComponent.h"





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
	GetCharacterMovement()->BrakingDecelerationFalling = 0;
	GetCharacterMovement()->AirControl = 0.1f;
	GetCharacterMovement()->FallingLateralFriction = 0;

	// Creates the grapple gun mesh
	GrappleGun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grapple Gun"));
	GrappleGun->SetupAttachment(FirstPersonCameraComponent);
	GrappleGun->SetVisibility(true);

	
	// Creates the mesh that the cable is attached to
	GrappleStartLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grapple Start Location"));
	GrappleStartLocation->SetupAttachment(GrappleGun);
	
	
	// Creates the grapple cable component
	GrappleCable = CreateDefaultSubobject<UCableComponent>(TEXT("Grapple Cable"));
	GrappleCable->SetupAttachment(GrappleStartLocation);
	GrappleCable->SetVisibility(false);

	

}

void AUniGDEVMechanicCharacter::BeginPlay() 
{
	Super::BeginPlay();

	// Set the mass at the start
	Mass = 100;


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

		// Extending
		EnhancedInputComponent->BindAction(ExtendGrappleAction, ETriggerEvent::Started, this, &AUniGDEVMechanicCharacter::ExtendGrapple);
		EnhancedInputComponent->BindAction(ExtendGrappleAction, ETriggerEvent::Completed, this, &AUniGDEVMechanicCharacter::StopExtending);

		// Reeling
		EnhancedInputComponent->BindAction(ReelGrappleAction, ETriggerEvent::Started, this, &AUniGDEVMechanicCharacter::ReelGrapple);
		EnhancedInputComponent->BindAction(ReelGrappleAction, ETriggerEvent::Completed, this, &AUniGDEVMechanicCharacter::StopReeling);
		



	}
	else
	{
		UE_LOG(LogUniGDEVMechanic, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AUniGDEVMechanicCharacter::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	if (bIsGrappling) 
	{

		Grappling();
	
	} 
	
}

void AUniGDEVMechanicCharacter::Grapple()
{
	
	if (bIsGrappling) 
	{
		StopGrapple();
		return;
	}
	// Get Capsule Component location
	FVector Start = GetFirstPersonCameraComponent()->GetComponentLocation();
	//Line trace of the grapple. Distance and direction.
	FVector End = Start + (MaxGrappleShootingDistance * UKismetMathLibrary::GetForwardVector(FirstPersonCameraComponent->GetComponentRotation()));
	

	// Populate HitResult with the first collision in the Grappleable trace channel. hasHit is true if there is any collision
	bHasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, FCollisionShape::MakeSphere(10.f));

	if (bHasHit) 
	{
		SetUpGrapple();

	}
}

void AUniGDEVMechanicCharacter::StopGrapple()
{
	bIsGrappling = false;
	bHasHit = false;
	
	GrappleCable->SetVisibility(false);
	GetCharacterMovement()->FallingLateralFriction = 0;
}

void AUniGDEVMechanicCharacter::ExtendGrapple()
{
	bIsExtending = true;
}

void AUniGDEVMechanicCharacter::ReelGrapple()
{
	bIsReeling = true;
	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Reeling"));
}

void AUniGDEVMechanicCharacter::StopExtending()
{
	bIsExtending = false;
}

void AUniGDEVMechanicCharacter::StopReeling()
{
	bIsReeling = false;
}

void AUniGDEVMechanicCharacter::MoveHook()
{
	CurrentHookDistance = (HookPoint - InitialFiringPoint).Size();
	if (CurrentHookDistance < InitialHookDistance)
	{
		HookPoint += HookDirection;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hook Moved"));
		
	}
	else if (CurrentHookDistance >= InitialHookDistance)
	{
		HookPoint = GrapplePoint;
		bHookHasFinishedMoving = true;
		//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Hook Finished Moving"));
	}
	// Get the end location using the grapple point transform
	GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(HookPoint);
}

void AUniGDEVMechanicCharacter::Grappling()
{
	GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(HookPoint);
	// Make sure theres no bouncing back when the reeling stops
	if (DistanceFromGrapplePoint < MaxGrappleDistance)
	{
		MaxGrappleDistance = DistanceFromGrapplePoint;
	}
	if (bHookHasFinishedMoving)
	{
		GetCharacterMovement()->FallingLateralFriction = 0.5;

		// Get player location
		PlayerPosition = GetActorLocation();
		//This block of code moves the player towards the grapple point while decreasing the distance the player can go from the grapple
		if (bIsReeling)
		{
			Reel();
	
		}

		// This block of code extends the distance the player can go from the grapple.
		if (bIsExtending)
		{
			Extend();

		}

		// This block of code restricts the distance that the player can go from the grapple.

		DistanceFromGrapplePoint = (PlayerPosition - GrapplePoint).Size();
		if (DistanceFromGrapplePoint > MaxGrappleDistance)
		{
			/* Finds the direction of the player from the grapple point, reverses it and then multiplies by some arbitrary values
			 and the magnitude of the velocity going towards the player (but only if the result of the dot product is above 0, it does not actually
			 find the magnitude if its negative because that causes bugs) */

			GetCharacterMovement()->AddForce(-((PlayerPosition - GrapplePoint).GetSafeNormal() * Mass * 100 * (CalculateDotProductCustom())));

		}
	}
	if (!bHookHasFinishedMoving)
	{
		MoveHook();
	}
}

void AUniGDEVMechanicCharacter::SetUpGrapple()
{
	    bIsGrappling = true;
		GrappleCable->SetVisibility(true);
		GrapplePoint = HitResult.ImpactPoint;

		PlayerPosition = GetActorLocation();
		// Finds float distance from grapple point
		DistanceFromGrapplePoint = (GrapplePoint - PlayerPosition).Size();
		// Sets this as the maximum distance from that point
		MaxGrappleDistance = DistanceFromGrapplePoint;

		// Set up the hook shooting
		HookPoint = GrappleStartLocation->GetComponentLocation();
		HookDirection = (GrapplePoint - HookPoint).GetSafeNormal() * HookSpeed;
		InitialHookDistance = (GrapplePoint - HookPoint).Size();
		InitialFiringPoint = GrappleStartLocation->GetComponentLocation();
		bHookHasFinishedMoving = false;
}

void AUniGDEVMechanicCharacter::Reel()
{
	// Applies more force when grounded to account for friction
	if (GetCharacterMovement()->MovementMode == MOVE_Walking)
	{
		GrappleSpeed = 1000000;
	}
	else
	{
		GrappleSpeed = 200000;
	}

	// Move Player towards the grapple point. The number that it is multiplied is the speed that the grapple is reeled in.
	GetCharacterMovement()->AddForce((GrapplePoint - GetActorLocation()).GetSafeNormal() * GrappleSpeed);

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Max Grap Distance: %f"), GrappleSpeed));
	DistanceFromGrapplePoint = (PlayerPosition - GrapplePoint).Size();
}

void AUniGDEVMechanicCharacter::Extend()
{
	MaxGrappleDistance += 1;
	DistanceFromGrapplePoint = (PlayerPosition - GrapplePoint).Size();
	MaxGrappleDistance = DistanceFromGrapplePoint;

}

float AUniGDEVMechanicCharacter::CalculateDotProductCustom() 
{
	// Magnitude of the velocity going in the direction of the player
	FVector Velocity = GetVelocity();
	FVector NormalizedDirection = (PlayerPosition - GrapplePoint).GetSafeNormal();
	float x = Velocity.X * NormalizedDirection.X;
	float y = Velocity.Y * NormalizedDirection.Y;
	float z = Velocity.Z * NormalizedDirection.Z;
	float DotProduct = x + y + z;
	
	// This function needs to do nothing if the result is less than 0 to avoid bouncy behaviour
    if (DotProduct < 0) 
	{
		DotProduct = 1.0;
	}
	return DotProduct;

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
