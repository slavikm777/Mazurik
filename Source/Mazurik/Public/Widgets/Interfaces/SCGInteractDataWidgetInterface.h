// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCGInteractDataWidgetInterface.generated.h"

UINTERFACE(MinimalAPI)
class USCGInteractDataWidgetInterface : public UInterface
{
    GENERATED_BODY()
};

class MAZURIK_API ISCGInteractDataWidgetInterface
{
    GENERATED_BODY()

public:
    virtual void SetName(FText InName) = 0;
    virtual void SetInteractText(FText InInteractText) = 0;
    virtual void ToggleWidget(bool InShow) = 0;
};
