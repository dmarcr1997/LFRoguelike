// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"

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

void ANeonLFExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel hit by %s"), *OtherActor->GetName());

	RadialForceComponent->FireImpulse();
}

// Called when the game starts or when spawned
void ANeonLFExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentHit.AddDynamic(this, &ANeonLFExplosiveBarrel::OnHit);
}

// Called every frame
void ANeonLFExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

