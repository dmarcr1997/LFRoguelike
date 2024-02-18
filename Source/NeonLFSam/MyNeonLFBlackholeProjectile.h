// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeonLFProjectile.h"
#include "MyNeonLFBlackholeProjectile.generated.h"

/**
 * 
 */
class URadialForceComponent;

UCLASS()
class NEONLFSAM_API AMyNeonLFBlackholeProjectile : public ANeonLFProjectile
{
	GENERATED_BODY()

public:
	AMyNeonLFBlackholeProjectile();

protected:
	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URadialForceComponent* RadialForceComponent;

};
