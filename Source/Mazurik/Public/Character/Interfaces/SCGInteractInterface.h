// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Objects/SCGInteractObject.h"
#include "SCGInteractInterface.generated.h"

UINTERFACE(MinimalAPI)
class USCGInteractInterface : public UInterface
{
    GENERATED_BODY()
};

class MAZURIK_API ISCGInteractInterface
{
    GENERATED_BODY()

public:
    virtual void LookActor(ASCGInteractObject* ActorInteracted) = 0;
    virtual void LeaveActor() = 0;
    virtual void TakeKey(FName KeyRowName) = 0;
};
