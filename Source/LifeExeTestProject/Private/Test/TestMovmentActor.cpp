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
		MI->SetVectorParameterValue("BaseColor", FLinearColor::Green);
		MI->SetVectorParameterValue("GradientMultiplier", FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
		MI->SetVectorParameterValue("GradientAddendum", FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
	}
	
	InitialLocation = GetActorLocation();
	InitialScale = GetActorScale3D();
}

void ATestMovmentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	switch(AnimationType)
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
	CurrentLocation.Z = InitialLocation.Z + MoveAnimAmplitude * FMath::Sin(Time * MoveAnimFrequency);
	SetActorLocation(CurrentLocation);
}

void ATestMovmentActor::DoScaleAnimation()
{
	FVector CurrentScale = GetActorScale3D();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentScale = InitialScale + ScaleAnimAmplitude * FMath::Abs(FMath::Sin(Time * ScaleAnimFrequency));
	SetActorScale3D(CurrentScale);
}