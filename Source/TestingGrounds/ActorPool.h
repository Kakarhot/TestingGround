// Yuri

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorPool();

	void AddToPool();

	void ReturnToPool();

	AActor* Checkout();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;



		
	
};
