// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCGHUDPlayerInterface.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnTogglePauseWidget);

UINTERFACE(MinimalAPI)
class USCGHUDPlayerInterface : public UInterface
{
    GENERATED_BODY()
};

class MAZURIK_API ISCGHUDPlayerInterface
{
    GENERATED_BODY()

public:
    virtual FOnTogglePauseWidget& OnTogglePauseWidget() = 0;
};
