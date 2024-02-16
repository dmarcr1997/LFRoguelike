// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFTargetDummy.h"
#include "NeonLFAttributeComponent.h"

// Sets default values
ANeonLFTargetDummy::ANeonLFTargetDummy()
{
     MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
     RootComponent = MeshComp;

     AttributeComp = CreateDefaultSubobject<UNeonLFAttributeComponent>("AttributComp");
     AttributeComp->OnHealthChanged.AddDynamic(this, &ANeonLFTargetDummy::OnHealthChanged);

}

void ANeonLFTargetDummy::OnHealthChanged(AActor* InstigatorActor, UNeonLFAttributeComponent* OwningComp, float NewHealth, float Delta)
{
     if (Delta < 0.0f) {
          MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
     }
}

