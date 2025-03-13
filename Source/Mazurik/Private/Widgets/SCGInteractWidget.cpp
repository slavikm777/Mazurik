// Mazurik V.V project

#include "Widgets/SCGInteractWidget.h"
#include "Components/TextBlock.h"

void USCGInteractWidget::SetName(FText InName)
{
    check(TextName);
    TextName->SetText(InName);
}

void USCGInteractWidget::SetInteractText(FText InInteractText)
{
    check(TextInteract);
    TextInteract->SetText(InInteractText);
}

void USCGInteractWidget::ToggleWidget(bool InShow)
{
    if (InShow)
        SetVisibility(ESlateVisibility::Visible);
    else SetVisibility(ESlateVisibility::Hidden);
}
