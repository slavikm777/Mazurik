// Mazurik V.V project

#include "Objects/SCGObjectsOpeningUp.h"

ASCGObjectsOpeningUp::ASCGObjectsOpeningUp()
{
    MeshMovable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshMovable"));
    check(MeshMovable);
    MeshMovable->SetupAttachment(RootComponent);
}

void ASCGObjectsOpeningUp::StartTheAction()
{
    if (CanAction)
        if (IsOpen)
            Close();
        else
            Open();
}

void ASCGObjectsOpeningUp::Open()
{
    PlayAnim();
    IsOpen = true; // В будущем сделать таймер или делегат
}

void ASCGObjectsOpeningUp::Close()
{
    PlayAnim(false);
    IsOpen = false; // В будущем сделать таймер или делегат
}
