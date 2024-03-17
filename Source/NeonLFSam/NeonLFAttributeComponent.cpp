// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonLFAttributeComponent.h"

// Sets default values for this component's properties
UNeonLFAttributeComponent::UNeonLFAttributeComponent()
{
	Health = HealthMax;
}



bool UNeonLFAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool UNeonLFAttributeComponent::ApplyHealthChange(float delta)
{
	Health = FMath::Clamp(Health + delta, 0, HealthMax);

	OnHealthChanged.Broadcast(nullptr, this, Health, delta);
	return true;
}

