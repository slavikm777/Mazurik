// Mazurik V.V project

#include "Character/SCGGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"

FOnTogglePauseWidget& ASCGGamePlayerController::OnTogglePauseWidget()
{
	return OnTogglePauseWidgetEvent;
}

void ASCGGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	UpdateInputMode();
}

void ASCGGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->ClearAllMappings();
		check(InputMappingContext);
		Subsystem->AddMappingContext(InputMappingContext, 0);
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			EnhancedInputComponent->BindAction(ActionPauseMenu, ETriggerEvent::Started, this, &ASCGGamePlayerController::TogglePauseWidget);
		}
	}
}

void ASCGGamePlayerController::TogglePauseWidget()
{
	bIsPauseShow = !bIsPauseShow;
	UpdateInputMode();
	OnTogglePauseWidgetEvent.Broadcast();
}

void ASCGGamePlayerController::UpdateInputMode()
{
	bShowMouseCursor = bIsPauseShow;
	if(bShowMouseCursor)
	{
		SetInputMode(FInputModeGameAndUI());
	}
	else
	{
		SetInputMode(FInputModeGameOnly());
	}
}
