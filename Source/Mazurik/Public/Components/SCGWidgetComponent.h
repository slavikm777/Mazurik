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
	FText ObjectName, InteractText;
	void ToggleWidgetInteraction(bool ShowWidget);
	void SetInteractText(FText InText);
	void SetObjectName(FText InText);

protected:
	virtual void BeginPlay() override;

private:
	ISCGInteractDataWidgetInterface* InteractDataWidgetInterface;
};
