// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SEPARATED_API UMainCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	//Variables to expose to the editor
	UPROPERTY(BlueprintReadOnly)
	float AnimationSpeed = 0.0f;
};
