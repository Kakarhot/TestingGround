// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"
#include "Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#include "ActorPool.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MinExtent = FVector(0, -2000, 0);
	MaxExtent = FVector(4000, 2000, 0);
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
}

void ATile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	//UE_LOG(LogTemp, Warning, TEXT("[%s] Returning: %s"), *(this->GetName()), *(NavMeshBoundsVolume->GetName()));
	//if (NavMeshBoundsVolume != nullptr) 
	//{
	//	
	//}
	Pool->Return(NavMeshBoundsVolume);
}

void ATile::SetPool(UActorPool * InPool)
{
	Pool = InPool;
	UE_LOG(LogTemp, Warning, TEXT("[%s] Setting Pool %s"), *(this->GetName()), *(InPool->GetName()));

	PositionNavMeshBoundsVolume();
}

void ATile::PositionNavMeshBoundsVolume()
{
	NavMeshBoundsVolume = Pool->Checkout();
	if (NavMeshBoundsVolume == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Not Enough Actors in Pool"), *(this->GetName()));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Check out: %s"), *(this->GetName()), *(NavMeshBoundsVolume->GetName()));

	NavMeshBoundsVolume->SetActorLocation(GetActorLocation());
}

void ATile::PlaceActors(TSubclassOf<AActor>ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale)
{
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint;
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		bool LocationFound = FindEmptyLocation(SpawnPoint, Radius*RandomScale);
		if (LocationFound) {
			float RandomRotation = FMath::RandRange(-180.f, 180.f);
			PlaceActor(ToSpawn, SpawnPoint, RandomRotation, RandomScale);
		}
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation, float Radius)
{
	FBox Bounds(MinExtent, MaxExtent);

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

	//FColor DrawColor = HasHit ? FColor::Red : FColor::Green;
	//DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, DrawColor, true, 100);

	return !HasHit;
}

void ATile::PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->SetActorRotation(FRotator(0, Rotation, 0));
	Spawned->SetActorScale3D(FVector(Scale));
}

