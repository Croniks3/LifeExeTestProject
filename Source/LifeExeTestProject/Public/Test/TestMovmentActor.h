#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMovmentActor.generated.h"


class UStaticMeshComponent;

UENUM()
enum class EAnimationType : uint8
{
	Static = 0,
	Move,
	Scale,
	All
};

UCLASS()
class LIFEEXETESTPROJECT_API ATestMovmentActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestMovmentActor();
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	EAnimationType AnimationType;

	UPROPERTY(EditAnywhere, Category="Animation")
	float MoveAnimAmplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	float MoveAnimFrequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Animation")
	FVector ScaleAnimAmplitude = FVector(1.0f);

	UPROPERTY(EditAnywhere, Category = "Animation")
	float ScaleAnimFrequency = 2.0f;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void DoScaleAnimation();

private:
	void DoMoveAnimation();

	FVector InitialLocation;
	FVector InitialScale;
};