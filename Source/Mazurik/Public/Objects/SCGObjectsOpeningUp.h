// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Objects/SCGInteractObject.h"
#include "SCGObjectsOpeningUp.generated.h"

UCLASS()
class MAZURIK_API ASCGObjectsOpeningUp : public ASCGInteractObject
{
    GENERATED_BODY()

public:
    ASCGObjectsOpeningUp();
    virtual bool StartTheAction() override;
    virtual void OnConstruction(const FTransform& Transform) override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* MeshMovable;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FText InteractText2;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
    FTransform TransformOpen;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
    FTransform TransformClose;

    virtual FText GetInteractText() override;

    UFUNCTION(BlueprintNativeEvent)
    void PlayAnimEvent(bool Open);

    void PlayAnim(bool Open = true);

    bool GetOpen() { return IsOpen; }

    UFUNCTION(BlueprintCallable)
    void FinishAnim();

private:
    UPROPERTY(EditAnywhere, Category = "Settings")
    bool IsOpen = false;
    void Open();
    void Close();
};
