#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActorCreator.generated.h"


UCLASS()
class LIFEEXETESTPROJECT_API ATestActorCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestActorCreator();

protected:
	virtual void BeginPlay() override;

//protected:
//	UPROPERTY()
//	TSubclassOf<ATestMovementActor> MYUPROPERTY;

public:	
	virtual void Tick(float DeltaTime) override;

};