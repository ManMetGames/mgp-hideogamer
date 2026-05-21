// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "UniGDEVMechanicCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A basic first person character
 */
UCLASS(abstract)
class AUniGDEVMechanicCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: first person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FirstPersonMesh;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category ="Input")
	class UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* GrappleAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* ExtendGrappleAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* ReelGrappleAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grapple", meta = (AllowPrivateAccess = "true"))
	class UCableComponent* GrappleCable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grapple", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* GrappleStartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grapple", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* GrappleGun;


	
public:
	AUniGDEVMechanicCharacter();

protected:

	virtual void BeginPlay() override;
	void Tick(float DeltaTime);

	

protected:

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Called from Input Actions for looking input */
	void LookInput(const FInputActionValue& Value);

	/** Handles aim inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoAim(float Yaw, float Pitch);

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles jump start inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump end inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

	

protected:

	/** Set up input action bindings */
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	

public:

	/** Returns the first person mesh **/
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Returns first person camera component **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

private:
	// Grapple methods
	void Grapple();
	void StopGrapple();

	// These make the grapple extend or decrease in length. They use different speed values, reeling is faster.
	void ExtendGrapple();
	void ReelGrapple();
	void StopExtending();
	void StopReeling();

	// Method that shoots the hook or pulls the hook towards the gun based on the bool inputted.
	void MoveHook();
	
	void Grappling();
	void SetUpGrapple();
	void Reel();
	void Extend();
	// Maths method that calculates the dot product in a SPECIFIC way for grapple maths only
	float CalculateDotProductCustom();

	float GrappleSpeed;

	float HookSpeed = 10;

	// range at which the grapple can be shot at
	float MaxGrappleShootingDistance = 2000.f;
	// adjustable value. It starts out with the distance the grapple point is from the player
	float MaxGrappleDistance;
	// measurement of the distance from the grapple point.
	float DistanceFromGrapplePoint;

	// Initial distance from the grapple starting point to the grapple point
	float InitialHookDistance;
	float CurrentHookDistance;
	bool bIsGrappling;
	bool bHookIsMoving;
	bool bHasHit;
	bool bIsExtending;
	bool bIsReeling;
	bool bHookHasFinishedMoving;

	// Point that the grapple hits and will pull the player towards.
	FVector GrapplePoint;

	// Temporary point used to simulate a projectile being shot, the grapple will be attached to this when firing until it reaches the grapple point and vice versa when it reaches the gun
	FVector HookPoint;
	FVector InitialFiringPoint;

	FVector HookDirection;

	// Player position, usually used to compare to the grapple point.
	FVector PlayerPosition;

	FHitResult HitResult;

	// Mass of player used for physics calculations. Kg.
	float Mass;

};

