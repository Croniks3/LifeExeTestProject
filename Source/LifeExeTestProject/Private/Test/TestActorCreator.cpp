#include "Test/TestActorCreator.h"


ATestActorCreator::ATestActorCreator()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATestActorCreator::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if(World)
	{
		for(const auto& SpawnPoint : SpawnPoints)
		{
			ATestMovementActor* SpawnedActor = World->SpawnActorDeferred<ATestMovementActor>(SpawnPoint.SpawnActorClass, SpawnPoint.Transform);
			if(SpawnedActor)
			{
				SpawnedActor->SetCommonData(SpawnPoint.SpawnActorCommonData);
				SpawnedActor->SetAnimationData(SpawnPoint.SpawnActorAnimationData);
				SpawnedActor->SetColorData(SpawnPoint.SpawnActorColorData);
				SpawnedActor->FinishSpawning(SpawnPoint.Transform);

#if WITH_EDITOR
				SpawnedActor->SetFolderPath(FName("TestMovementActors"));
#endif
			}
		}
	}
}

void ATestActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}