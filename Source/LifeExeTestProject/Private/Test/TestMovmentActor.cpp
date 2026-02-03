#include "Test/TestMovmentActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogTestMovementActor, All, All);


ATestMovmentActor::ATestMovmentActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

void ATestMovmentActor::BeginPlay()
{
	Super::BeginPlay();
	
	MaterialInstanceDynamic = Mesh->CreateDynamicMaterialInstance(0);
	if(MaterialInstanceDynamic)
	{
		MaterialInstanceDynamic->SetVectorParameterValue("BaseColor", ColorData.BaseColor);
		MaterialInstanceDynamic->SetVectorParameterValue("GradientMultiplier", ColorData.GradientMultiplier);
		MaterialInstanceDynamic->SetVectorParameterValue("GradientAddendum", ColorData.GradientAddendum);
	}
	
	InitialLocation = GetActorLocation();
	InitialScale = GetActorScale3D();

	if(ColorData.bRandomColorByTimer == true)
	{
		GetWorldTimerManager().SetTimer
		(
			ColorData.RandomColorTimerHandle,
			this,
			&ThisClass::OnRandomColorTimerFired,
			ColorData.RandomColorTimerRate,
			true
		);
	}
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

void ATestMovmentActor::OnRandomColorTimerFired()
{
	const FLinearColor NewColor = FLinearColor::MakeRandomColor();
	MaterialInstanceDynamic->SetVectorParameterValue("BaseColor", NewColor);
	UE_LOG(LogTestMovementActor, Display, TEXT("Color to set up: %s"), *NewColor.ToString());
}