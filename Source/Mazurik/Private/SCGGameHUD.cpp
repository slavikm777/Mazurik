// Mazurik V.V project

#include "SCGGameHUD.h"
#include "Widgets/SCGGameHUDWidget.h"

void ASCGGameHUD::BeginPlay()
{
    Super::BeginPlay();
    check(ClassGameHUDWidget)
    {
        USCGGameHUDWidget* GameHUDWidget = CreateWidget<USCGGameHUDWidget>(GetOwningPlayerController(), ClassGameHUDWidget);
        GameHUDWidget->AddToViewport();
        UE_LOG(LogTemp, Warning, TEXT("WidgetCreated!"));
    }
}
