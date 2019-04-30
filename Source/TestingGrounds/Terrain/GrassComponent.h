// Yuri

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GrassComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UGrassComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UGrassComponent();

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	int SpawnCount;

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	FBox SpawnExtent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
