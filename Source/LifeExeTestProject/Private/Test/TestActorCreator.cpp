#include "Test/TestActorCreator.h"
#include "Test/TestMovementActor.h"


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
		//World->SpawnActor();
	}
}

void ATestActorCreator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}