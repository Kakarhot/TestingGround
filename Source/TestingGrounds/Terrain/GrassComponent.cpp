// Yuri

#include "GrassComponent.h"

UGrassComponent::UGrassComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < SpawnCount; i++) {
		FVector NewPoint = FMath::RandPointInBox(SpawnExtent);
		AddInstance(FTransform(NewPoint));
	}
}
