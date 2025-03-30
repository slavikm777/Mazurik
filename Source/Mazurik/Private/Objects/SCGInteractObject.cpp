// Mazurik V.V project

#include "Objects/SCGInteractObject.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Character/Interfaces/SCGInteractInterface.h"
#include "Components/SCGWidgetComponent.h"

ASCGInteractObject::ASCGInteractObject()
{
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    check(MeshComponent);
    SetRootComponent(MeshComponent);
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
    check(SphereComponent);
    SphereComponent->SetSphereRadius(100.0f);
    SphereComponent->SetupAttachment(RootComponent);
    WidgetInteract = CreateDefaultSubobject<USCGWidgetComponent>(TEXT("WidgetInteract"));
    check(WidgetInteract);
    WidgetInteract->SetupAttachment(RootComponent);

    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OverlapEnd);
}

void ASCGInteractObject::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                      const FHitResult& SweepResult)
{
    InteractInterface = Cast<ISCGInteractInterface>(OtherActor);
    if (InteractInterface)
        InteractInterface->LookActor(this);
    WidgetInteract->ToggleWidgetInteraction(true);
}

void ASCGInteractObject::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if(InteractInterface)
    {
        InteractInterface->LeaveActor();
        InteractInterface = nullptr;
    }
    WidgetInteract->ToggleWidgetInteraction(false);
}

void ASCGInteractObject::BeginPlay()
{
    Super::BeginPlay();
    WidgetInteract->SetInteractText(GetInteractText());
    WidgetInteract->SetObjectName(Name);
}
