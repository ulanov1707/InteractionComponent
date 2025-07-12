// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractonComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/PlayerCameraManager.h"
#include "InteractionArea.h"

// Sets default values for this component's properties
UInteractonComponent::UInteractonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ..
}


// Called when the game starts
void UInteractonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UInteractonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Trace();
}

void UInteractonComponent::Trace()
{
	FHitResult HitResult;

	FVector StartTrace = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();
	FVector EndTrace = (UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraRotation().Vector()) * TraceLenght + StartTrace;

	
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility,FCollisionQueryParams(),FCollisionResponseParams());
	if (bHit) 
	{
		//If the hit actor is not the focus actor
		if (HitResult.GetActor() != FocusedActor) 
		{
			FocusedActor = HitResult.GetActor();
			
			TraceInteractionArea(FocusedActor->IsA(AInteractionArea::StaticClass()));

		}
	}
	else 
	{
		TraceInteractionArea(false);
	}
	
}

void UInteractonComponent::TraceInteractionArea(bool Trace)
{
	if (Trace == true) 
	{
		if (IsTracingInteractionArea == true && FocusedInteracionArea != nullptr) //Unfoucs
		{
				FocusedInteracionArea->ToggleFocus(false);
		}

		FocusedInteracionArea = Cast<AInteractionArea>(FocusedActor);

		if (IsValid(FocusedActor)) 
		{
			FocusedInteracionArea->ToggleFocus(true);
			IsTracingInteractionArea = true;
		}
		
	}
	else 
	{
		if (IsTracingInteractionArea == true) 
		{
			IsTracingInteractionArea = false;
			if (IsValid(FocusedInteracionArea)) 
			{
				FocusedInteracionArea->ToggleFocus(false);
			}
			FocusedActor = nullptr;
			FocusedInteracionArea = nullptr;
		}
	}
}
