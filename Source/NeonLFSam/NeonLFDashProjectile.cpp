// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFDashProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

void ANeonLFDashProjectile::Explode_Implementation()
{
	GetWorldTimerManager().ClearTimer(Timer_DelayedDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
	EffectComp->DeactivateSystem();

	MovementComp->StopMovementImmediately();
	SetActorEnableCollision(false);
	FTimerHandle Timer_DelayedTeleport;
	GetWorldTimerManager().SetTimer(Timer_DelayedTeleport, this, &ANeonLFDashProjectile::TeleportInstigator, TeleportDelay);
}

void ANeonLFDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ensure(ActorToTeleport))
	{
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
	}
}

void ANeonLFDashProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Timer_DelayedDetonate, this, &ANeonLFDashProjectile::Explode, DetonateDelay);
}

ANeonLFDashProjectile::ANeonLFDashProjectile()
{

	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	MovementComp->InitialSpeed = 6000.0f;
}
