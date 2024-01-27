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
	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* RadialForceComponent;

};
