// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Classes/Engine/World.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATile::PlaceActors(TSubclassOf<AActor>ToSpawn, int MinSpawn, int MaxSpawn)
{
	FBox Bounds(FVector(0, -2000, 0), FVector(4000, 2000, 0));
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int i = 0; i < NumberToSpawn; i++)
	{
		auto NewPoint = FMath::RandPointInBox(Bounds);

		AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		Spawned->SetActorRelativeLocation(NewPoint);
		
	}

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

