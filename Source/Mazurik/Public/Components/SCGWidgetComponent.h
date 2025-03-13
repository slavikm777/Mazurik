// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "SCGWidgetComponent.generated.h"

class USCGInteractWidget;
class ISCGInteractDataWidgetInterface;

UCLASS()
class MAZURIK_API USCGWidgetComponent final : public UWidgetComponent
{
	GENERATED_BODY()

public:
	void ToggleWidgetInteraction(bool ShowWidget);

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FText ObjectName;

	UPROPERTY(EditAnywhere, Category = "Settings")
	FText InteractText;

	virtual void BeginPlay() override;

private:
	ISCGInteractDataWidgetInterface* InteractDataWidgetInterface;
};
