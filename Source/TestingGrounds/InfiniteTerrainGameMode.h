// Yuri

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
	
	
public:


	UFUNCTION(BlueprintCallable)
	void PopulateBoundsVolumePool();
	
private:
	void AddToPool(class ANavMeshBoundsVolume* ActorToAdd);
};
