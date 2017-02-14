// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "AnotherCharacter.h"


// Sets default values
AAnotherCharacter::AAnotherCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnotherCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnotherCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAnotherCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

//Implement CalculateHealth
void AAnotherCharacter::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}

//Implement CalculateDead
void AAnotherCharacter::CalculateDead()
{
	if (Health <= 0)
		isDead = true;
	else
		isDead = false;
}

//Implement PostEditChangeProperty
#if WITH_EDITOR

void AAnotherCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;

	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif