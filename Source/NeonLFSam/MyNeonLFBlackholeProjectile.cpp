// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNeonLFBlackholeProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

AMyNeonLFBlackholeProjectile::AMyNeonLFBlackholeProjectile() : ANeonLFProjectile()
{
	ProjectileSpeed = 600.0f;
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AMyNeonLFBlackholeProjectile::OnActorOverlap);
	MovementComp->InitialSpeed = 600.0f;
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->SetupAttachment(SphereComp);
	RadialForceComponent->SetAutoActivate(true);
	RadialForceComponent->Radius = 7500.0f;
	RadialForceComponent->ImpulseStrength = -2500.0f;
	RadialForceComponent->bImpulseVelChange = true;
	RadialForceComponent->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

void AMyNeonLFBlackholeProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator()) {
		OtherActor->Destroy();
	}
}
