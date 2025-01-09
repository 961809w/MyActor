// MyActor.cpp
#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true; // Tick 함수를 사용하겠다는 의미
	CurrentPosition = FVector2D(0, 0); //시작 위치
	StepCount = 0; //시작 횟수
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // Initial log
    UE_LOG(LogTemp, Warning, TEXT("Actor spawned at starting position: (%d, %d)"), (int32)CurrentPosition.X, (int32)CurrentPosition.Y);
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (StepCount < 10)
    {
        MoveRandomly();
        StepCount++;
    }
}

void AMyActor::MoveRandomly()
{
	//랜덤하게 움직일 방향을 결정
    int32 DeltaX = FMath::RandRange(-1, 1);
    int32 DeltaY = FMath::RandRange(-1, 1);

	//새로운 위치 계산
    FVector2D NewPosition = CurrentPosition + FVector2D(DeltaX, DeltaY);

	// 새로운 위치가 현재 위치에서 1칸 이내인지 확인
    if (FMath::Abs(NewPosition.X - CurrentPosition.X) < 2 &&
        FMath::Abs(NewPosition.Y - CurrentPosition.Y) < 2)
    {
        CurrentPosition = NewPosition;

        //로그 출력
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current Position: (%d, %d)"), StepCount + 1, (int32)CurrentPosition.X, (int32)CurrentPosition.Y);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid move generated, retrying..."));
    }

}
//확률에 따라 이벤트를 발생시키는 함수
void TriggerEventWithProbability(float Probability)
{
    int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
    if (RandomValue <= Probability)
    {
        UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
    }
}
//두 점 사이의 거리를 계산하는 함수
float distance(FVector2D first, FVector2D second)
{
    float dx = first.X - second.X;
    float dy = first.Y - second.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
    
}
