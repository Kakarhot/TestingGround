// Yuri

#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Add: %s"), *ActorToAdd->GetName())
}
