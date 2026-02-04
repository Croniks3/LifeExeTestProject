#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test/TestMovementActor.h"
#include "TestActorCreator.generated.h"


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
	TSubclassOf<ATestMovementActor> SpawnActorClass;

	UPROPERTY(EditAnywhere, Category = "SpawnActorSettings")
	FColorData SpawnActorColorData;

	UPROPERTY(EditAnywhere, Category = "SpawnActorSettings")
	FAnimationData SpawnActorAnimationData;

public:	
	virtual void Tick(float DeltaTime) override;

};