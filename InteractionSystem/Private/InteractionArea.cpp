// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionArea.h"

// Sets default values
AInteractionArea::AInteractionArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractionArea::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

