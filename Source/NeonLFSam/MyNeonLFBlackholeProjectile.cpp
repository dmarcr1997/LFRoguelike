// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNeonLFBlackholeProjectile.h"
#include "PhysicsEngine/RadialForceComponent.h"

AMyNeonLFBlackholeProjectile::AMyNeonLFBlackholeProjectile() : ANeonLFProjectile()
{
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->SetupAttachment(RootComponent);
	RadialForceComponent->SetAutoActivate(true);
	RadialForceComponent->Radius = 750.0f;
	RadialForceComponent->ImpulseStrength = 2500.0f;
	RadialForceComponent->bImpulseVelChange = true;
}
