// MyActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYMY_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    // 이 엑터의 속성을 초기화하는 기본 값 설정
    AMyActor();

protected:
    // 게임이 시작되거나 스폰될 때 호출
    virtual void BeginPlay() override;

public:
    // 매 프레임마다 호출
    virtual void Tick(float DeltaTime) override;

private:
    // 엑터의 현재 위치
    FVector2D CurrentPosition;

    // 움직인 횟수
    int32 StepCount;

    // 총 이동 거리
    float TotalDistance;

    // 총 이벤트 발생 횟수
    int32 TotalEventsTriggered;

    // 랜덤하게 움직이는 함수
    void MoveRandomly();

    // 두 점 사이의 거리를 계산하는 함수
    float distance(FVector2D first, FVector2D second);

    // FVector2D 배열 데이터를 출력하는 함수
    void PrintFVector2DArray();

    // 확률에 따라 이벤트를 발생시키는 함수
    void TriggerEventWithProbability(float Probability);
};
