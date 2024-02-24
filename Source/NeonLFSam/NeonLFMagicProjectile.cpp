// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFMagicProjectile.h"
#include "NeonLFAttributeComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ANeonLFMagicProjectile::ANeonLFMagicProjectile()
{
	SphereComp->SetSphereRadius(20.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ANeonLFMagicProjectile::OnActorOverlap);

	DamageAmount = 20.0f;

}

void ANeonLFMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator()) {
		UNeonLFAttributeComponent* AttributeComp = Cast<UNeonLFAttributeComponent>(OtherActor->GetComponentByClass(UNeonLFAttributeComponent::StaticClass()));
		if (AttributeComp) {
			AttributeComp->ApplyHealthChange(-DamageAmount);
			Explode();
		}
	}
}
