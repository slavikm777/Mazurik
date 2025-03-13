// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCGUserWidget.h"
#include "Widgets/Interfaces/SCGInteractDataWidgetInterface.h"
#include "SCGInteractWidget.generated.h"

class UTextBlock;

UCLASS(Abstract)
class MAZURIK_API USCGInteractWidget final : public USCGUserWidget, public ISCGInteractDataWidgetInterface
{
    GENERATED_BODY()

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ActionText;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextInteract;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextName;

private:
    virtual void SetName(FText InName);
    virtual void SetInteractText(FText InInteractText);
    virtual void ToggleWidget(bool InShow);
};
