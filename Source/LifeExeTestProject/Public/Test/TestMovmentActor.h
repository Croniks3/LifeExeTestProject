#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMovmentActor.generated.h"


class UStaticMeshComponent;

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

	UPROPERTY(EditAnywhere, Category="Movement")
	float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector ScaleAmplitude = FVector(1.0f);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float ScaleFrequency = 2.0f;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AnimateByScale();

private:
	FVector InitialLocation;
	FVector InitialScale;
};