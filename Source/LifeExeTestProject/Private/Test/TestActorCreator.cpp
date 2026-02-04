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
			ATestMovementActor* SpawnActor = World->SpawnActorDeferred<ATestMovementActor>(SpawnPoint.SpawnActorClass, SpawnPoint.Transform);
			SpawnActor->SetAnimationData(SpawnPoint.SpawnActorAnimationData);
			SpawnActor->SetColorData(SpawnPoint.SpawnActorColorData);
			SpawnActor->FinishSpawning(SpawnPoint.Transform);

#if WITH_EDITOR
			SpawnActor->SetFolderPath(FName("TestMovementActors"));
#endif
		}
	}
}

void ATestActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}