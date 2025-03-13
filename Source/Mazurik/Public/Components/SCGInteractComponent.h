// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SCGInteractComponent.generated.h"

class ASCGInteractObject;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAZURIK_API USCGInteractComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    void StartInteract(ASCGInteractObject* InInteractObject);
    void StopInteract();
    void Interact();

private:
    UPROPERTY()
    ASCGInteractObject* InteractObject;
};
