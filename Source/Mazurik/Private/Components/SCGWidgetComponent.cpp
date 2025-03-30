// Mazurik V.V project

#include "Components/SCGWidgetComponent.h"
#include "Widgets/SCGInteractWidget.h"

void USCGWidgetComponent::ToggleWidgetInteraction(bool ShowWidget)
{
    check(InteractDataWidgetInterface) InteractDataWidgetInterface->ToggleWidget(ShowWidget);
}

void USCGWidgetComponent::SetInteractText(FText InText)
{
    InteractText = InText;
    if (InteractDataWidgetInterface)
        InteractDataWidgetInterface->SetInteractText(InteractText);
}

void USCGWidgetComponent::SetObjectName(FText InText)
{
    ObjectName = InText;
    if (InteractDataWidgetInterface)
        InteractDataWidgetInterface->SetName(ObjectName);
}

void USCGWidgetComponent::BeginPlay()
{
    Super::BeginPlay();
    if (GetWidget())
    {
        InteractDataWidgetInterface = Cast<USCGInteractWidget>(GetWidget());
        if (InteractDataWidgetInterface)
        {
            InteractDataWidgetInterface->SetInteractText(InteractText);
            InteractDataWidgetInterface->SetName(ObjectName);
            InteractDataWidgetInterface->ToggleWidget(false);
        }
    }
}
