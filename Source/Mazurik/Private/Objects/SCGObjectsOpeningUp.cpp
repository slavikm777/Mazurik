// Mazurik V.V project

#include "Objects/SCGObjectsOpeningUp.h"
#include "Components/SCGWidgetComponent.h"

ASCGObjectsOpeningUp::ASCGObjectsOpeningUp()
{
    MeshMovable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMovable"));
    check(MeshMovable);
    MeshMovable->SetupAttachment(RootComponent);
    MeshMovable->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    check(WidgetInteract);
}

bool ASCGObjectsOpeningUp::StartTheAction()
{
    Super::StartTheAction();
    if (CanAction)
        if (IsOpen)
            Close();
        else
            Open();
    return true;
}

void ASCGObjectsOpeningUp::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    if (MeshMovable)
    {
        if (IsOpen)
            MeshMovable->SetRelativeTransform(TransformOpen);
        else MeshMovable->SetRelativeTransform(TransformClose);
    }
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
    IsOpen = true; 
    WidgetInteract->SetInteractText(GetInteractText());
}

void ASCGObjectsOpeningUp::Close()
{
    PlayAnim(false);
    IsOpen = false;
    WidgetInteract->SetInteractText(GetInteractText());
}
