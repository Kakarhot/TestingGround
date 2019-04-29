// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Classes/Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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



void ATile::PlaceActors(TSubclassOf<AActor>ToSpawn, int MinSpawn, int MaxSpawn, float Radius)
{
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint;
		bool LocationFound = FindEmptyLocation(SpawnPoint, Radius);
		if (LocationFound) {
			PlaceActor(ToSpawn, SpawnPoint);
		}
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation, float Radius)
{
	FBox Bounds(FVector(0, -2000, 0), FVector(4000, 2000, 0));

	const int MAX_ATTEMPTS = 100;
	for (int i = 0; i <= MAX_ATTEMPTS; i++) {
		FVector NewPoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(NewPoint, Radius)) {
			OutLocation = NewPoint;
			return true;
		}
	}
	return false;
}

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);

	FColor DrawColor = HasHit ? FColor::Red : FColor::Green;

	DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, DrawColor, true, 100);
	return !HasHit;
}

void ATile::PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRelativeLocation(SpawnPoint);
}

