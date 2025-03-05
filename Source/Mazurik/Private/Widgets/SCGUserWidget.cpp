// Mazurik V.V project

#include "Widgets/SCGUserWidget.h"

void USCGUserWidget::Show()
{
	if (IsVisible()) return;
	SetVisibility(ESlateVisibility::Visible);
}

void USCGUserWidget::Hide()
{
	if (!IsVisible()) return;
	SetVisibility(ESlateVisibility::Hidden);
}

void USCGUserWidget::Toggle()
{
	IsVisible() ? Hide() : Show();
}
