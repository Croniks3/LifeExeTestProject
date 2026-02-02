#include "Test/TestMovmentActor.h"
#include "Components/StaticMeshComponent.h"


ATestMovmentActor::ATestMovmentActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

void ATestMovmentActor::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
	InitialScale = GetActorScale3D();
}

void ATestMovmentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * Time);
	SetActorLocation(CurrentLocation);
}

void ATestMovmentActor::AnimateByScale()
{
	FVector CurrentScale = GetActorScale3D();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentScale = InitialScale + ScaleAmplitude * FMath::Abs(FMath::Sin(Time * ScaleFrequency));
	SetActorScale3D(CurrentScale);
}