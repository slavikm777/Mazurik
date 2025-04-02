// Mazurik V.V project

#include "Components/SCGInteractComponent.h"
#include "Objects/SCGInteractObject.h"
#include "Objects/Interfaces/SCGLockDoorInterface.h"

void USCGInteractComponent::StartInteract(ASCGInteractObject* InInteractObject)
{
    LockDoorInterface = Cast<ISCGLockDoorInterface>(InInteractObject);
    InteractObject = InInteractObject;
}

void USCGInteractComponent::StopInteract()
{
    if (InteractObject)
        InteractObject = nullptr;
    if (LockDoorInterface)
        LockDoorInterface = nullptr;
}

void USCGInteractComponent::Interact(TArray<FName> Keys) const
{
    if (LockDoorInterface)
    {
        if (LockDoorInterface->GetOpen())
        {
            InteractObject->StartTheAction();
            return;
        }
        else
        {
            for (FName Key : Keys)
            {
                if (LockDoorInterface->OpenDoorWithLock(FName(Key)))
                    return;
            }
        }
        return;
    }
    if (InteractObject)
        InteractObject->StartTheAction();
}
