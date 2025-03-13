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
    IsOpen = true; // � ������� ������� ������ ��� �������
}

void ASCGObjectsOpeningUp::Close()
{
    PlayAnim(false);
    IsOpen = false; // � ������� ������� ������ ��� �������
}
