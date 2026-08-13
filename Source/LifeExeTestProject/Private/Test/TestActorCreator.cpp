#include "Test/TestActorCreator.h"


ATestActorCreator::ATestActorCreator()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATestActorCreator::BeginPlay()
{
	Super::BeginPlay();
	
	if(UWorld* World = GetWorld())
	{
		for(const FSpawnPointInfo& SpawnPoint : SpawnPoints)
		{
			if(ATestMovementActor* SpawnedActor = World->SpawnActorDeferred<ATestMovementActor>(SpawnPoint.SpawnActorClass, SpawnPoint.Transform))
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