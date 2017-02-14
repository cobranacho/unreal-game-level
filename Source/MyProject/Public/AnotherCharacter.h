// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "AnotherCharacter.generated.h"

UCLASS(Blueprintable)
class MYPROJECT_API AAnotherCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AnotherCharacter")
		float Health = 100;

	// Make a isDead property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "AnotherCharacter")
		bool isDead = false;

	// Calculate death function (helper)
	virtual void CalculateDead();

	// Calculate health function
	UFUNCTION(BlueprintCallable, Category = "AnotherCharacter")
		virtual void CalculateHealth(float delta);

	// Editor-centric code for changing property

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) 
		override;
#endif

public:
	// Sets default values for this character's properties
	AAnotherCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
};
