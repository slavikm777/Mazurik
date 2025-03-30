// Mazurik V.V project

#include "Objects/SCGObjectsOpeningUp.h"
#include "Components/SCGWidgetComponent.h"

ASCGObjectsOpeningUp::ASCGObjectsOpeningUp()
{
    MeshMovable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMovable"));
    check(MeshMovable);
    MeshMovable->SetupAttachment(RootComponent);
    check(WidgetInteract);
}

void ASCGObjectsOpeningUp::StartTheAction()
{
    if (CanAction)
        if (IsOpen)
            Close();
        else
            Open();
}

FText ASCGObjectsOpeningUp::GetInteractText()
{
    if (IsOpen)
        return InteractText2;
    else
        return InteractText;
}

void ASCGObjectsOpeningUp::PlayAnim(bool Open)
{
    CanAction = false;
    UE_LOG(LogTemp, Warning, TEXT("Implementation false"));
    PlayAnimEvent(Open);
}

void ASCGObjectsOpeningUp::FinishAnim()
{
    CanAction = true;
}

void ASCGObjectsOpeningUp::PlayAnimEvent_Implementation(bool Open)
{
}

void ASCGObjectsOpeningUp::Open()
{
    PlayAnim();
    IsOpen = true; // В будущем сделать таймер или делегат
    WidgetInteract->SetInteractText(GetInteractText());
}

void ASCGObjectsOpeningUp::Close()
{
    PlayAnim(false);
    IsOpen = false; // В будущем сделать таймер или делегат
    WidgetInteract->SetInteractText(GetInteractText());
}
