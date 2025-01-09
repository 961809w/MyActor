//My Actor class header file
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

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
    // Current position of the actor
    FVector2D CurrentPosition;

    // Step counter
    int32 StepCount;

    // Function to perform random movement
    void MoveRandomly();
};