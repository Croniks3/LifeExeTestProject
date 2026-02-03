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
		MI->SetVectorParameterValue("BaseColor", ColorData.BaseColor);
		MI->SetVectorParameterValue("GradientMultiplier", ColorData.GradientMultiplier);
		MI->SetVectorParameterValue("GradientAddendum", ColorData.GradientAddendum);
	}
	
	InitialLocation = GetActorLocation();
	InitialScale = GetActorScale3D();
}

void ATestMovmentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	switch(AnimationData.AnimationType)
	{
		case EAnimationType::Move:
			DoMoveAnimation();
			break;
		case EAnimationType::Scale:
			DoScaleAnimation();
			break;
		case EAnimationType::All:
			DoMoveAnimation();
			DoScaleAnimation();
			break;
		default:
			break;
	}
}

void ATestMovmentActor::DoMoveAnimation()
{
	FVector CurrentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + AnimationData.MoveAmplitude * FMath::Sin(Time * AnimationData.MoveFrequency);
	SetActorLocation(CurrentLocation);
}

void ATestMovmentActor::DoScaleAnimation()
{
	FVector CurrentScale = GetActorScale3D();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentScale = InitialScale + AnimationData.ScaleAmplitude * FMath::Abs(FMath::Sin(Time * AnimationData.ScaleFrequency));
	SetActorScale3D(CurrentScale);
}