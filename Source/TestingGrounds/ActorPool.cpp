// Yuri

#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor * UActorPool::Checkout()
{
	UE_LOG(LogTemp, Warning, TEXT("Checkout"));

	return nullptr;
}

void UActorPool::ReturnToPool(AActor* ActorToReturn)
{
	if (ActorToReturn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null pointer"), *(this->GetName()));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("Return"));



}

void UActorPool::AddToPool(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null pointer"), *(this->GetName()));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor add"), *(this->GetName()));
}







