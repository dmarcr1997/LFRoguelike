// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NeonLFTargetDummy.generated.h"

class UNeonLFAttributeComponent;

UCLASS()
class NEONLFSAM_API ANeonLFTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANeonLFTargetDummy();

protected:
	
	UPROPERTY(VisibleAnywhere)
	UNeonLFAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, UNeonLFAttributeComponent* OwningComp, float NewHealth, float Delta);

	

};
