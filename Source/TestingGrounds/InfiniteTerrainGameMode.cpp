// Yuri

#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "ActorPool.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode() : Super()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(TEXT("Nav Mesh Bounds Volume Pool"));
}

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
	
}


void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume* ActorToAdd)
{
	NavMeshBoundsVolumePool->Add(ActorToAdd);
}
