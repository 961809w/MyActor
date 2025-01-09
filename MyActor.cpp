// MyActor.cpp
#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true; // Enable ticking
    CurrentPosition = FVector2D(0, 0); // Starting point
    StepCount = 0;
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
    // Generate random movement values for X and Y within {-1, 0, 1}
    int32 DeltaX = FMath::RandRange(-1, 1);
    int32 DeltaY = FMath::RandRange(-1, 1);

    // Update position
    FVector2D NewPosition = CurrentPosition + FVector2D(DeltaX, DeltaY);

    // Ensure the movement doesn't exceed the maximum allowed distance
    if (FMath::Abs(NewPosition.X - CurrentPosition.X) < 2 &&
        FMath::Abs(NewPosition.Y - CurrentPosition.Y) < 2)
    {
        CurrentPosition = NewPosition;

        // Log the new position
        UE_LOG(LogTemp, Warning, TEXT("Step %d: Current Position: (%d, %d)"), StepCount + 1, (int32)CurrentPosition.X, (int32)CurrentPosition.Y);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid move generated, retrying..."));
    }
}
