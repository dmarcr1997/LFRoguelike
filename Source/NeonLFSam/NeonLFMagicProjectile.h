// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeonLFProjectile.h"
#include "NeonLFMagicProjectile.generated.h"


UCLASS()
class NEONLFSAM_API ANeonLFMagicProjectile : public ANeonLFProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANeonLFMagicProjectile();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DamageAmount;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
