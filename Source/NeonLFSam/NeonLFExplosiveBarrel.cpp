// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ANeonLFExplosiveBarrel::ANeonLFExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetSimulatePhysics(true);
	RootComponent = MeshComponent;

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->SetupAttachment(MeshComponent);


}

// Called when the game starts or when spawned
void ANeonLFExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonLFExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

