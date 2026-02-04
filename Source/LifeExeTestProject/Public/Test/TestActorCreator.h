#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test/TestMovementActor.h"
#include "TestActorCreator.generated.h"


USTRUCT(BlueprintType)
struct FSpawnPointInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget))
	FTransform Transform;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATestMovementActor> SpawnActorClass;
	
	UPROPERTY(EditAnywhere)
	FColorData SpawnActorColorData;

	UPROPERTY(EditAnywhere)
	FAnimationData SpawnActorAnimationData;
};

UCLASS()
class LIFEEXETESTPROJECT_API ATestActorCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestActorCreator();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "SpawnActorSettings")
	TArray<FSpawnPointInfo> SpawnPoints;

public:	
	virtual void Tick(float DeltaTime) override;

};