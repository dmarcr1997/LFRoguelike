// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"

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
	RadialForceComponent->SetAutoActivate(false);
	RadialForceComponent->Radius = 750.0f;
	RadialForceComponent->ImpulseStrength = 2500.0f;
	RadialForceComponent->bImpulseVelChange = true;

	RadialForceComponent->AddCollisionChannelToAffect(ECC_WorldDynamic);

}

void ANeonLFExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComponent->FireImpulse();

	UE_LOG(LogTemp, Log, TEXT("Blow up barrel"));
	UE_LOG(LogTemp, Warning, TEXT("Other Actor: %s, at game time: %f"), *GetNameSafe(OtherActor), GetWorld()->TimeSeconds);

	FString CominedString = FString::Printf(TEXT("Hit at location: %s"), *Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CominedString, nullptr, FColor::Green, 2.0f, true);
}

void ANeonLFExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MeshComponent->OnComponentHit.AddDynamic(this, &ANeonLFExplosiveBarrel::OnHit);
}

