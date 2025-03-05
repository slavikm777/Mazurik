// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCGUserWidget.h"
#include "SCGGameHUDWidget.generated.h"

class USCGPauseUW;

UCLASS()
class MAZURIK_API USCGGameHUDWidget final : public USCGUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    USCGPauseUW* PauseWidget;
};
