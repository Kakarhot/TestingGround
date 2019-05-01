// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"


class UActorPool;

UCLASS()
class TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UPROPERTY(BlueprintReadWrite)
	class UActorPool* ActorPool;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void PlaceActors(TSubclassOf<AActor>ToSpawn, int MinSpawn=1, int MaxSpawn=1, float Radius=500, float MinScale=1, float MaxScale=1);

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void SetPool(UActorPool* InPool);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void PositionNavMeshBoundsVolume();

	bool CanSpawnAtLocation(FVector Location, float Radius);

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor>ToSpawn, FVector SpawnPoint, float Rotation, float Scale);

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
	
};
