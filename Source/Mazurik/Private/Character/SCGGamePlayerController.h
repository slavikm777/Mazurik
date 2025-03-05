// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Character/SCGPlayerController.h"
#include "Character/Interfaces/SCGHUDPlayerInterface.h"
#include "SCGGamePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS(Abstract)
class ASCGGamePlayerController final : public ASCGPlayerController, public ISCGHUDPlayerInterface
{
    GENERATED_BODY()

public:
    virtual FOnTogglePauseWidget& OnTogglePauseWidget() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* InputMappingContext;
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* ActionPauseMenu;

    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    bool bIsPauseShow = false;
    FOnTogglePauseWidget OnTogglePauseWidgetEvent;
    void TogglePauseWidget();
    void UpdateInputMode();
};
