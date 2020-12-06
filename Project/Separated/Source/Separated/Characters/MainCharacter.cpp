// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Separated/AnimInstances/MainCharacterAnimInstance.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Set up player input bindings.
	PlayerInputComponent->BindAxis("MoveYAxis", this, &AMainCharacter::MoveYAxis);
	PlayerInputComponent->BindAxis("MoveXAxis", this, &AMainCharacter::MoveXAxis);
	PlayerInputComponent->BindAxis("LookYAxis", this, &AMainCharacter::LookYAxis);
	PlayerInputComponent->BindAxis("LookXAxis", this, &AMainCharacter::LookXAxis);
}

void AMainCharacter::LookXAxis(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AMainCharacter::LookYAxis(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMainCharacter::MoveYAxis(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
        // Send axis speed to the AnimInstance to be used in Animation Blueprint.
	UMainCharacterAnimInstance* AnimInstance = Cast<UMainCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInstance->AnimationSpeed = AxisValue;
}

void AMainCharacter::MoveXAxis(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}




