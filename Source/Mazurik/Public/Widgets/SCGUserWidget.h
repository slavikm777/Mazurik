// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SCGUserWidget.generated.h"

UCLASS(Abstract)
class MAZURIK_API USCGUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void Show();
    void Hide();
    void Toggle();
};
