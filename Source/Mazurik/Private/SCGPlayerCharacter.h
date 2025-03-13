// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Character/SCGBaseCharacter.h"
#include "Character/Interfaces/SCGInteractInterface.h"
#include "SCGPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class USCGInteractComponent;

struct FInputActionValue;

UCLASS(Abstract)
class ASCGPlayerCharacter : public ASCGBaseCharacter, public ISCGInteractInterface
{
    GENERATED_BODY()

public:
    ASCGPlayerCharacter();
    virtual void LookActor(ASCGInteractObject* ActorInteracted) override;
    virtual void LeaveActor() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    USpringArmComponent* CameraBoom;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UCameraComponent* FollowCamera;
    UPROPERTY()
    USCGInteractComponent* InteractComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Settings | Input")
    UInputAction* ActionMove;
    UPROPERTY(EditDefaultsOnly, Category = "Settings | Input")
    UInputAction* ActionLook;
    UPROPERTY(EditDefaultsOnly, Category = "Settings | Input")
    UInputAction* ActionInteract;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void Interact();
};
