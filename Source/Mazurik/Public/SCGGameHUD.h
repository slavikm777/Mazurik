// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "SCGBaseHUD.h"
#include "SCGGameHUD.generated.h"

class USCGGameHUDWidget;

UCLASS(Abstract)
class MAZURIK_API ASCGGameHUD final : public ASCGBaseHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Settings")
    TSubclassOf<USCGGameHUDWidget> ClassGameHUDWidget;

    virtual void BeginPlay() override;

    FTimerHandle Timer;
    void Test();
};
