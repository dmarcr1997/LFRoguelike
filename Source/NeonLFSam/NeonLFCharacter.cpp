// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
ANeonLFCharacter::ANeonLFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ANeonLFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANeonLFCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ANeonLFCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
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
	PlayerInputComponent->BindAxis("MoveForward",this, &ANeonLFCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANeonLFCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

}

