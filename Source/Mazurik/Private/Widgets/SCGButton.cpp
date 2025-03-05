// Mazurik V.V project

#include "Widgets/SCGButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

FOnButtonClickedEvent& USCGButton::OnClicked() const
{
    check(Button);
    return Button->OnClicked;
}

void USCGButton::NativePreConstruct()
{
    Super::NativePreConstruct();
    if (TextBlock)
    {
        TextBlock->SetText(TextButton);
        FSlateFontInfo FontInfo = TextBlock->Font;
        FontInfo.Size = TextSize;
        TextBlock->SetFont(FontInfo);
    }
}
