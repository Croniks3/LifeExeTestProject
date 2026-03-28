#include "Test/TestMovementActor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogTestMovementActor, All, All);

#pragma region ActorMethods

ATestMovementActor::ATestMovementActor()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
}

void ATestMovementActor::BeginPlay()
{
	Super::BeginPlay();
	
	if(CommonData.StaticMesh)
	{
		MeshComponent->SetStaticMesh(CommonData.StaticMesh);
	}

	MaterialInstanceDynamic = MeshComponent->CreateDynamicMaterialInstance(0);
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

void ATestMovementActor::Tick(float DeltaTime)
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

#pragma endregion

#pragma region GetterAndSetterMethods

void ATestMovementActor::SetCommonData(const FCommonData& InCommonData)
{
	CommonData = InCommonData;
}

void ATestMovementActor::SetAnimationData(const FAnimationData& InAnimationData)
{
	AnimationData = InAnimationData;
}

void ATestMovementActor::SetColorData(const FColorData& InColorData)
{
	ColorData = InColorData;
}

#pragma endregion

void ATestMovementActor::DoMoveAnimation()
{
	FVector CurrentLocation = GetActorLocation();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + AnimationData.MoveAmplitude * FMath::Sin(Time * AnimationData.MoveFrequency);
	SetActorLocation(CurrentLocation);
}

void ATestMovementActor::DoScaleAnimation()
{
	FVector CurrentScale = GetActorScale3D();
	float Time = GetWorld()->GetTimeSeconds();
	CurrentScale = InitialScale + AnimationData.ScaleAmplitude * FMath::Abs(FMath::Sin(Time * AnimationData.ScaleFrequency));
	SetActorScale3D(CurrentScale);
}

void ATestMovementActor::OnRandomColorTimerFired()
{
	if(MaterialInstanceDynamic)
	{
		const FLinearColor NewColor = FLinearColor::MakeRandomColor();
		MaterialInstanceDynamic->SetVectorParameterValue("BaseColor", NewColor);
		/*UE_LOG(LogTestMovementActor, Display, TEXT("(%s(%s)) Color to set up: %s"),
			*GetActorLabel(), ANSI_TO_TCHAR(__FUNCTION__), *NewColor.ToString());*/
	}
}