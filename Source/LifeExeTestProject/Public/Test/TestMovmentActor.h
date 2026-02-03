#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMovmentActor.generated.h"


class UStaticMeshComponent;

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
	EAnimationType AnimationType;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor BaseColor = FLinearColor::Green;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor GradientMultiplier = FLinearColor::Black;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor GradientAddendum = FLinearColor::White;
};

UCLASS()
class LIFEEXETESTPROJECT_API ATestMovmentActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestMovmentActor();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ConfigData")
	FAnimationData AnimationData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ConfigData")
	FColorData ColorData;

	UFUNCTION(BlueprintCallable)
	void DoScaleAnimation();
	
private:
	FVector InitialLocation;
	FVector InitialScale;

	void DoMoveAnimation();
};