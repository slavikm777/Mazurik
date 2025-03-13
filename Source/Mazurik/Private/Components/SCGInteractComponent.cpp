// Mazurik V.V project

#include "Components/SCGInteractComponent.h"
#include "Objects/SCGInteractObject.h"

void USCGInteractComponent::StartInteract(ASCGInteractObject* InInteractObject)
{
    InteractObject = InInteractObject;
}

void USCGInteractComponent::StopInteract()
{
    if (InteractObject)
        InteractObject = nullptr;
}

void USCGInteractComponent::Interact()
{
    if (InteractObject)
        InteractObject->StartTheAction();
}
