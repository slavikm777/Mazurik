// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCGUserWidget.h"
#include "SCGButton.generated.h"

class UButton;
class UTextBlock;
class FOnButtonClickedEvent;

UCLASS(Abstract)
class MAZURIK_API USCGButton final : public USCGUserWidget
{
    GENERATED_BODY()

public:
    FOnButtonClickedEvent& OnClicked() const;

protected:
    UPROPERTY(EditAnywhere, Category = "Settings")
    FText TextButton;

    UPROPERTY(EditAnywhere, Category = "Settings")
    float TextSize = 40.0f;

    UPROPERTY(meta = (BindWidget))
    UButton* Button;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextBlock;

    virtual void NativePreConstruct() override;
};
