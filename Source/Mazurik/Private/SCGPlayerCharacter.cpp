// Mazurik V.V project

#include "SCGPlayerCharacter.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "Components/SCGInteractComponent.h"

ASCGPlayerCharacter::ASCGPlayerCharacter()
{
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->TargetArmLength = 400.0f;
    CameraBoom->SetRelativeLocation(FVector(0, 0, 30));
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom);
    GetCharacterMovement()->bOrientRotationToMovement = true;
    bUseControllerRotationYaw = false;
    InteractComponent = CreateDefaultSubobject<USCGInteractComponent>(TEXT("InteractComponent"));
}

void ASCGPlayerCharacter::LookActor(ASCGInteractObject* ActorInteracted)
{
    InteractComponent->StartInteract(ActorInteracted);
    UE_LOG(LogTemp, Warning, TEXT("LookOnObject"));
}

void ASCGPlayerCharacter::LeaveActor()
{
    InteractComponent->StopInteract();
    UE_LOG(LogTemp, Warning, TEXT("LeaveFromObject"));
}

void ASCGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(ActionMove);
    check(ActionLook);
    check(ActionInteract);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &ASCGPlayerCharacter::Move);
        EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered, this, &ASCGPlayerCharacter::Look);
        EnhancedInputComponent->BindAction(ActionInteract, ETriggerEvent::Started, this, &ASCGPlayerCharacter::Interact);
    }
}

void ASCGPlayerCharacter::Move(const FInputActionValue& Value)
{
    check(GetController());
    FVector2D MovementVector = Value.Get<FVector2D>();
    const FRotator Rotation = GetController()->GetControlRotation();
    const FRotator YawRotation{ 0.0f, Rotation.Yaw, 0.0f };
    const FVector ForwardDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X) };
    const FVector RightDirection{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y) };
    AddMovementInput(ForwardDirection, MovementVector.Y);
    AddMovementInput(RightDirection, MovementVector.X);
}

void ASCGPlayerCharacter::Look(const FInputActionValue& Value)
{
    check(GetController());
    FVector2D LookVector = Value.Get<FVector2D>();
    AddControllerYawInput(LookVector.X);
    AddControllerPitchInput(LookVector.Y);
}

void ASCGPlayerCharacter::Interact()
{
    InteractComponent->Interact();
}
