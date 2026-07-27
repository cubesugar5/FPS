// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

AShooterPlayerController::AShooterPlayerController()
{
	
	bReplicates = true;
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem =  ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if(IsValid(Subsystem))
	{
		Subsystem->AddMappingContext(ShooterIMC, 0);
		
	}
}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* ShooterInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	ShooterInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	ShooterInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	ShooterInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Jump);

	ShooterInputComponent->BindAction(CrouchAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Crouch);
	
	
}

void AShooterPlayerController::Input_Crouch()
{
}

void AShooterPlayerController::Input_Jump()
{
}

void AShooterPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
}

void AShooterPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
}
