// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractonComponent.generated.h"

// handles interaction with Renotaion interacion actors
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) , Blueprintable)
class SHOESTORESIMULATOR_API UInteractonComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void TraceInteractionArea(bool Trace);


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	void Trace();

	UPROPERTY(EditAnywhere, Category = "Interacton",BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float TraceLenght = 400.f;
	
	UPROPERTY(VisibleAnywhere,Category = "Interaction")
	TObjectPtr<AActor> FocusedActor;
	
	UPROPERTY()
	bool IsTracingInteractionArea;

	UPROPERTY()
	TObjectPtr<class AInteractionArea> FocusedInteracionArea;
};
