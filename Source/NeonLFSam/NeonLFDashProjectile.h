// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeonLFProjectile.h"
#include "NeonLFDashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class NEONLFSAM_API ANeonLFDashProjectile : public ANeonLFProjectile
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonateDelay;

	FTimerHandle Timer_DelayedDetonate;

	virtual void Explode_Implementation() override;

	void TeleportInstigator();

	virtual void BeginPlay() override;

public:

	ANeonLFDashProjectile();
	
};
