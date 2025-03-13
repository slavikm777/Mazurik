// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCGInteractObject.generated.h"

class UStaticMeshComponent;
// class UStaticMesh;
class USphereComponent;
class ISCGInteractInterface;
class USCGWidgetComponent;

UCLASS(Abstract)
class MAZURIK_API ASCGInteractObject : public AActor
{
    GENERATED_BODY()

public:
    ASCGInteractObject();

    virtual void StartTheAction() 
    {
        UE_LOG(LogTemp, Warning, TEXT("InteractWithActor"));
    };

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    USphereComponent* SphereComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Components")
    USCGWidgetComponent* WidgetInteract;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FString Name;

    bool CanAction = true;

    ISCGInteractInterface* InteractInterface;

    UFUNCTION(BlueprintNativeEvent)
    void PlayAnimEvent(bool Open);

    UFUNCTION(BlueprintCallable)
    void FinishAnim();

    UFUNCTION()
    virtual void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
        const FHitResult& SweepResult);
    UFUNCTION()
    virtual void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void PlayAnim(bool Open = true);
};
