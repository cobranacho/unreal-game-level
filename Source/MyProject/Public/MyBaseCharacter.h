// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyBaseCharacter.generated.h"

UCLASS(Blueprintable)
class MYPROJECT_API AMyBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MyBaseCharacter")
		float Health = 100;


	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "MyBaseCharacter")
		bool isDead = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "MyBaseCharacter")
		bool reactToPlayer = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "MyBaseCharacter")
		bool enableAttack = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "MyBaseCharacter")
		bool biteCorpes = false;

	virtual void CalculateDead();

	UFUNCTION(BlueprintCallable, Category = "MyBaseCharacter")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif



public:
	// Sets default values for this character's properties
	AMyBaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
