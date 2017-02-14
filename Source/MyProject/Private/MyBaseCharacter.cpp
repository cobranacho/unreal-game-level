// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyBaseCharacter.h"


// Sets default values
AMyBaseCharacter::AMyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyBaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void AMyBaseCharacter::CalculateHealth(float Delta)
{
	Health += Delta;
	CalculateDead();
}

//Step 2: Implement the CalculateDead function.
void AMyBaseCharacter::CalculateDead()
{
	if (Health <= 0)
		isDead = true;
	else
		isDead = false;

}
#if WITH_EDITOR

void AMyBaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	isDead = false;
	Health = 100;

	
	Super::PostEditChangeProperty(PropertyChangedEvent);

	CalculateDead();
}
#endif
