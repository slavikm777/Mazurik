// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCGUserWidget.h"
#include "SCGPauseUW.generated.h"

class USCGButton;

UCLASS(Abstract)
class MAZURIK_API USCGPauseUW final : public USCGUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    USCGButton* Replay;
    UPROPERTY(meta = (BindWidget))
    USCGButton* Settings;
    UPROPERTY(meta = (BindWidget))
    USCGButton* SaveGame;
    UPROPERTY(meta = (BindWidget))
    USCGButton* GoToMainMenu;
    UPROPERTY(meta = (BindWidget))
    USCGButton* Exit;
};
