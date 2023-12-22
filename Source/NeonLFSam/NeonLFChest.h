// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NeonLFGameplayInterface.h"
#include "NeonLFChest.generated.h"

UCLASS()
class NEONLFSAM_API ANeonLFChest : public AActor, public INeonLFGameplayInterface
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere)
	float TargetPitch = 110;
	
	void Interact_Implementation(APawn* InstigatorPawn);

	// Sets default values for this actor's properties
	ANeonLFChest();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
