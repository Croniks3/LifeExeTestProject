#include "Test/TestMovmentActor.h"

// Sets default values
ATestMovmentActor::ATestMovmentActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestMovmentActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestMovmentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}