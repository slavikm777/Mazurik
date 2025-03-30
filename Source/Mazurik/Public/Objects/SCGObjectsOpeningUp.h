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
    virtual void StartTheAction() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* MeshMovable;

    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    FText InteractText2;

    virtual FText GetInteractText() override;

    UFUNCTION(BlueprintNativeEvent)
    void PlayAnimEvent(bool Open);

    void PlayAnim(bool Open = true);

    UFUNCTION(BlueprintCallable)
    void FinishAnim();

private:
    UPROPERTY(EditAnywhere, Category = "Settings")
    bool IsOpen = false;
    void Open();
    void Close();
};
