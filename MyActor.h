//My Actor class header file
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
#include <iostream>

UCLASS()
class MYMY_API AMyActor : public AActor
{
    GENERATED_BODY()

public: 
    // Sets default values for this actor's properties
    AMyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
	//현재 위치
    FVector2D CurrentPosition;

	//현재 위치에서 움직인 횟수
    int32 StepCount;

	//랜덤하게 움직이는 함수
    void MoveRandomly();

	//확률에 따라 이벤트를 발생시키는 함수
	void TriggerEventWithProbability(float Probability);

	//두 점 사이의 거리를 계산하는 함수
	float distance(FVector2D a, FVector2D b);
};
