// Mazurik V.V project

#include "Widgets/SCGGameHUDWidget.h"
#include "Widgets/SCGPauseUW.h"
#include "Helpers/SCGHelperFunctions.h"
#include "Character/Interfaces/SCGHUDPlayerInterface.h"

void USCGGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(!GetOwningPlayerPawn())
	{
		Hide();
		return;
	}

	PauseWidget->Hide();

	ISCGHUDPlayerInterface* HUDPlayerInterface = Cast<ISCGHUDPlayerInterface>(GetOwningPlayerPawn()->GetController());
	check(HUDPlayerInterface);
	HUDPlayerInterface->OnTogglePauseWidget().AddUObject(PauseWidget, &ThisClass::Toggle);
}
