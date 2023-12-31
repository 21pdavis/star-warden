	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/UserWidget.h"
#include "SpaceshipPlayerPawn.generated.h"

/**
 *	Set up following this tutorial: https://www.youtube.com/watch?v=4wWIjlkSj2w
 */
UCLASS()
class MEGAJAMSPACESHIP_API ASpaceshipPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceshipPlayerPawn();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// handle input to update location
	void Move(const struct FInputActionValue& ActionValue);

	// handle input to update rotation
	void Rotate(const struct FInputActionValue& ActionValue);

	// handle input to enable free flying
	void ToggleFreeFly();

	// handle input/disable boost
	void Boost();
	void StopBoost();
	
	// Sphere to use for root component (everything rotate together) and collision
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Collision;

	// Static mesh for the body of the spaceship, attached to root.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Body;

	// Spring arm to attach camera to root
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	// Camera attached to spring arm to provide pawn's view
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	// floating pawn movement smooths out movement
	UPROPERTY(EditAnywhere)
	class UFloatingPawnMovement* Movement;

	// Editable Fields
	// Scale to apply to location input (speed)
	UPROPERTY(EditAnywhere)
	float MoveScale;

	// Scale to apply to rotation input (mouse sensitivity)
	UPROPERTY(EditAnywhere)
	float RotateScale;

	UPROPERTY(EditAnywhere)
	float BoostMultiplier;
	
	UPROPERTY(EditAnywhere)
	float SpringArmLength;

	UPROPERTY(EditAnywhere)
	float BoostZoomOut;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> HUDWidgetClass;

	// Whether to use free flying mode
	uint32 bFreeFly:1;

	// Whether to use boost mode
	uint32 bBoost:1;

	// Maximum offset of ship
	uint32 MaximumShipOffset;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
};
