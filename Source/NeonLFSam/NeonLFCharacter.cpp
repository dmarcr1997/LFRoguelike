// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFCharacter.h"

// Sets default values
ANeonLFCharacter::ANeonLFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeonLFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonLFCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANeonLFCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

