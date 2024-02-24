// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANeonLFProjectile::ANeonLFProjectile()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentHit.AddDynamic(this, &ANeonLFProjectile::OnActorHit);
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = ProjectileSpeed;
	MovementComp->ProjectileGravityScale = 0.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

}

void ANeonLFProjectile::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}

void ANeonLFProjectile::Explode_Implementation()
{
	if (ensure(!IsPendingKill()))
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
		Destroy();
	}
}

void ANeonLFProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

/*
	Take shared functionality from projectiles
1) Magic Projectile(Exists)
2) Blackhole Projectile (New)

Implemented as Action. Can re-use a lot of the work we have already done.

Projectile class spawned via key input (same as MagicProjectile)
RadialForceComponent, but using continuous ‘Force’ (Not Impulse) to pull-in Actors.
Ignore ‘Pawn’ collision object type. (Player must remain unaffected of pull)
SphereComponent to ‘Destroy’ actors on overlap (black hole)
Must only destroy ‘simulating’ actors.
Particle Component for the black hole VFX.
Destroy itself after ~5 seconds (match the particle system duration)
Unique features made in Blueprints! That means the logic to suck up and destroy actors. // Binding of input in Character and spawning of projectile still done in C++ as we did with Magic Projectile.

3) Dash/Teleport Projectile Ability. (New)

Projectile class spawned via input key (same as MagicProjectile)
ParticleComponent to show projectile
‘Explodes’ after 0.2 seconds. (Timer)
Play particle effect at point of detonation.
Waits 0.2 seconds again (Timer) before Teleporting PlayerCharacter (aka the ‘Instigator’ of the projectile)
// Let the detonation effect play before we teleport
// Make sure you ‘stop’ the projectile movement while you wait(!)
// Look back at ‘Instigator’ we used for ignoring collisions, and re-apply here for teleportation.
On hit with world: immediately stop movement and execute the same behavior (explode + teleport)
Made in C++! (Only applies to the logic, assigning of assets is always done in Blueprint child class)
*/
