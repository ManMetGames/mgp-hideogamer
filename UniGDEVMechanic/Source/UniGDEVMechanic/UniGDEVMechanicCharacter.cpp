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
#include "GrappleConstraint.h"




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
	GetCharacterMovement()->AirControl = 2.0f;

	// Creates the grapple gun mesh
	GrappleGun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grapple Gun"));
	GrappleGun->SetupAttachment(FirstPersonCameraComponent);
	GrappleGun->SetVisibility(true);

	
	// Creates the mesh that the cable is attached to
	GrappleStartLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grapple Start Location"));
	GrappleStartLocation->SetupAttachment(GrappleGun);
	
	// Creates the mesh that the cable end location will be attached to. Purely visual
	GrappleHook = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grapple Hook"));
	GrappleHook->SetupAttachment(GrappleStartLocation);
	
	// Limits the distance from the grapple point
	//GrapplePhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Physics Constraint Component"));
	//GrapplePhysicsConstraint->SetupAttachment(GrappleStartLocation);
	
	
	// Creates the grapple cable component
	GrappleCable = CreateDefaultSubobject<UCableComponent>(TEXT("Grapple Cable"));
	GrappleCable->SetupAttachment(GrappleStartLocation);
	GrappleCable->SetVisibility(false);

	

}

void AUniGDEVMechanicCharacter::BeginPlay() 
{
	Super::BeginPlay();


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
		// Disable friction
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);

		// Get player location
		PlayerPosition = GetActorLocation();
		
		// Get the end location using the grapple point transform
	    GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(GrapplePoint);

		//GrappleHook->(GrapplePoint, false, 0, ETeleportType::None);
		//GrappleHook->RelativeLocation

		
		

		// Finds float distance from grapple point
		DistanceFromGrapplePoint = (GrapplePoint - PlayerPosition).Size();
		if (DistanceFromGrapplePoint > MaxGrappleDistance) 
		{
			GetCharacterMovement()->AddForce(GetVelocity()-(CalculateDotProductCustom()*(GrapplePoint - PlayerPosition).GetSafeNormal())*18000);
		}


		// Move Player towards the grapple point. The number that it is multiplied is the speed that the grapple is reeled in.
		//GetCharacterMovement()->AddForce((GrapplePoint - GetActorLocation()).GetSafeNormal() * 300000);

		
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
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	// Populate HitResult with the first collision in the Grappleable trace channel. hasHit is true if there is any collision
	bHasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, FCollisionShape::MakeSphere(10.f));

	if (bHasHit) 
	{
		bIsGrappling = true;
		GrappleCable->SetVisibility(true);
		GrapplePoint = HitResult.ImpactPoint;

		PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		// Finds float distance from grapple point
		DistanceFromGrapplePoint = (GrapplePoint - PlayerPosition).Size();
		// Sets this as the maximum distance from that point
		MaxGrappleDistance = DistanceFromGrapplePoint;

		/*FActorSpawnParameters SpawnInfo;
		UPrimitiveComponent* GrappleConstraintPoint = GetWorld()->SpawnActor<UPrimitiveComponent>(GrappleConstraintClass, GrapplePoint, SpawnRotation);
		UE_LOG(LogTemp, Warning, TEXT("Object created"));
		GrapplePhysicsConstraint->SetConstrainedComponents(GrappleConstraintPoint, "", GetCapsuleComponent(), "");

		PlayerPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		// Finds float distance from grapple point
		DistanceFromGrapplePoint = (GrapplePoint - PlayerPosition).Size();
		// Sets this as the maximum distance from that point
		MaxGrappleDistance = DistanceFromGrapplePoint;
		GrapplePhysicsConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Limited, MaxGrappleDistance);
		GrapplePhysicsConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Limited, MaxGrappleDistance);
		GrapplePhysicsConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Limited, MaxGrappleDistance);*/

	}
}

void AUniGDEVMechanicCharacter::StopGrapple()
{
	bIsGrappling = false;
	bHasHit = false;
	
	if (!GetCharacterMovement()->IsFalling()) 
	{
		// disable friction
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
	}
	GrappleCable->SetVisibility(false);
}

float AUniGDEVMechanicCharacter::CalculateDotProductCustom() 
{
	FVector Velocity = GetVelocity();
	FVector NormalizedDirection = (GrapplePoint - PlayerPosition).GetSafeNormal();
	float x = Velocity.X * NormalizedDirection.X;
	float y = Velocity.Y * NormalizedDirection.Y;
	float z = Velocity.Z * NormalizedDirection.Z;
	float DotProduct = x + y + z;
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
