#include "Test/TestMovmentActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"


ATestMovmentActor::ATestMovmentActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

void ATestMovmentActor::BeginPlay()
{
	Super::BeginPlay();
	
	UMaterialInstanceDynamic* MI = Mesh->CreateDynamicMaterialInstance(0);
	if(MI)
	{
		MI->SetVectorParameterValue("BaseColor", FLinearColor::Yellow);
		MI->SetVectorParameterValue("GradientMultiplier", FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
		MI->SetVectorParameterValue("GradientAddendum", FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
	}
	
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