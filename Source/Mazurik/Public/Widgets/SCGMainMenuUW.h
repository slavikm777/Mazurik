// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCGUserWidget.h"
#include "SCGMainMenuUW.generated.h"

class USCGButton;

UCLASS(Abstract)
class MAZURIK_API USCGMainMenuUW final : public USCGUserWidget
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    USCGButton* NewGame;
    UPROPERTY(meta = (BindWidget))
    USCGButton* LoadGame;
    UPROPERTY(meta = (BindWidget))
    USCGButton* Settings;
    UPROPERTY(meta = (BindWidget))
    USCGButton* Exit;
};
