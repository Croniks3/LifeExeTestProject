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
		const FTransform& SelfTransform = GetTransform();

		ATestMovementActor* NewActor = World->SpawnActorDeferred<ATestMovementActor>(SpawnActorClass, SelfTransform);
		NewActor->SetAnimationData(SpawnActorAnimationData);
		NewActor->SetColorData(SpawnActorColorData);
		NewActor->FinishSpawning(SelfTransform);

#if WITH_EDITOR
		NewActor->SetFolderPath(FName("TestMovementActors"));
#endif
	}
}

void ATestActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}