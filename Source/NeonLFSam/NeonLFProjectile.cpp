// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ANeonLFProjectile::ANeonLFProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = ProjectileSpeed;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;

}

// Called when the game starts or when spawned
void ANeonLFProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonLFProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
