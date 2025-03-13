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

private:
    UPROPERTY(EditAnywhere, Category = "Settings")
    bool IsOpen = false;
    void Open();
    void Close();
};
