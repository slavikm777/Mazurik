// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCGLockDoorInterface.generated.h"

UINTERFACE(MinimalAPI)
class USCGLockDoorInterface : public UInterface
{
    GENERATED_BODY()
};

class MAZURIK_API ISCGLockDoorInterface
{
    GENERATED_BODY()

public:
    virtual bool OpenDoorWithLock(FName KeyRowName) = 0;
    virtual bool GetOpen() = 0;
};
