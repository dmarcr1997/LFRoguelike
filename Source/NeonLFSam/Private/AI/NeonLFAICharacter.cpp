// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/NeonLFAICharacter.h"

// Sets default values
ANeonLFAICharacter::ANeonLFAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeonLFAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonLFAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
