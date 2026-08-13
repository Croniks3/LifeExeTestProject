#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "TestMovementActor.generated.h"


class UStaticMeshComponent;
class UMaterialInstanceDynamic;

UENUM(BlueprintType)
enum class EAnimationType : uint8
{
	Static = 0,
	Move,
	Scale,
	All
};

USTRUCT(BlueprintType)
struct FAnimationData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EAnimationType AnimationType = EAnimationType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveAmplitude = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveFrequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector ScaleAmplitude = FVector(1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ScaleFrequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RotationSpeedByZ = 360.0f;
};

USTRUCT(BlueprintType)
struct FColorData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FLinearColor BaseColor = FLinearColor::Green;

	UPROPERTY(EditAnywhere)
	FLinearColor GradientMultiplier = FLinearColor::Black;

	UPROPERTY(EditAnywhere)
	FLinearColor GradientAddendum = FLinearColor::White;

	UPROPERTY(EditAnywhere)
	bool bRandomColorByTimer{false};

	UPROPERTY(EditAnywhere)
	float RandomColorTimerRate = 3.0f;

	FTimerHandle RandomColorTimerHandle;
};

USTRUCT(BlueprintType)
struct FCommonData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	UStaticMesh* StaticMesh = nullptr;
};

UCLASS()
class LIFEEXETESTPROJECT_API ATestMovementActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestMovementActor();
	virtual void Tick(float DeltaTime) override;

public:
	void SetCommonData(const FCommonData& InCommonData);
	void SetAnimationData(const FAnimationData& InAnimationData);
	void SetColorData(const FColorData& InColorData);
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ConfigData")
	FAnimationData AnimationData;

	UPROPERTY(EditAnywhere, Category = "ConfigData")
	FColorData ColorData;

	UPROPERTY(EditAnywhere, Category = "ConfigData")
	FCommonData CommonData;

	UFUNCTION(BlueprintCallable)
	void DoScaleAnimation();

private:
	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstanceDynamic;

	FVector InitialLocation;
	FVector InitialScale;
	
	void DoMoveAnimation();
	void OnRandomColorTimerFired() const;
};