// Yuri

#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "ActorPool.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavBoundsVolumePool = CreateDefaultSubobject<UActorPool>(TEXT("Pool"));
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
	NavBoundsVolumePool->AddToPool(ActorToAdd);
}
