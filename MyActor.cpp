// MyActor.cpp
#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true; // Tick 함수를 활성화
    CurrentPosition = FVector2D(0, 0); // 시작 위치 설정
    StepCount = 0;
    TotalDistance = 0.0f; // 총 이동 거리 초기화
    TotalEventsTriggered = 0; // 총 이벤트 발생 횟수 초기화
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // 초기 위치 로그 출력
    UE_LOG(LogTemp, Warning, TEXT("Actor spawned at starting position: (%d, %d)"), (int32)CurrentPosition.X, (int32)CurrentPosition.Y);

    // FVector2D 배열 출력
    PrintFVector2DArray();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (StepCount < 10)
    {
        MoveRandomly();
        StepCount++;

        // 마지막 스텝인지 확인
        if (StepCount == 10)
        {
            // 총 결과 출력 (총 이동 거리도 정수로 출력)
            UE_LOG(LogTemp, Warning, TEXT("Total Distance Moved: %d"), (int32)TotalDistance);
            UE_LOG(LogTemp, Warning, TEXT("Total Events Triggered: %d"), TotalEventsTriggered);
        }
    }
}

void AMyActor::MoveRandomly()
{
    FVector2D PreviousPosition = CurrentPosition;

    // X와 Y의 랜덤 이동 값 생성 {-1, 0, 1} 범위
    int32 DeltaX = FMath::RandRange(-1, 1);
    int32 DeltaY = FMath::RandRange(-1, 1);

    // 새로운 위치 계산
    FVector2D NewPosition = CurrentPosition + FVector2D(DeltaX, DeltaY);

    // 이동 거리가 최대 허용 거리를 초과하지 않는지 확인
    if (FMath::Abs(NewPosition.X - CurrentPosition.X) < 2 &&
        FMath::Abs(NewPosition.Y - CurrentPosition.Y) < 2)
    {
        CurrentPosition = NewPosition; // 위치 업데이트

        // 거리 계산 및 총 이동 거리 업데이트
        float DistanceMoved = distance(PreviousPosition, CurrentPosition);
        TotalDistance += DistanceMoved; // 총 이동 거리 누적

        // 스텝 세부 정보 로그 출력
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current Position: (%d, %d), Distance Moved: %d"), StepCount + 1, (int32)CurrentPosition.X, (int32)CurrentPosition.Y, (int32)DistanceMoved);

        // 랜덤 이벤트 발생
        TriggerEventWithProbability(50.0f); // 50% 확률로 이벤트 발생
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid move generated, retrying...")); // 잘못된 이동 시 로그 출력
    }
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
    float dx = first.X - second.X;
    float dy = first.Y - second.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
    int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
    if (RandomValue <= Probability)
    {
        TotalEventsTriggered++; // 이벤트 발생 횟수 증가
        UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
    }
}

void AMyActor::PrintFVector2DArray()
{
    // FVector2D 배열 생성
    TArray<FVector2D> VectorArray;

    // 데이터 추가
    for (int32 i = 0; i < 10; i++)
    {
        VectorArray.Add(FVector2D(i * 10.0f, i * 20.0f)); // X, Y 값을 임의로 설정
    }

    // 데이터 출력
    for (int32 i = 0; i < VectorArray.Num(); i++)
    {
        const FVector2D& Vec = VectorArray[i];
        UE_LOG(LogTemp, Warning, TEXT("Vector %d: X = %d, Y = %d"), i, (int32)Vec.X, (int32)Vec.Y);
    }
}
