// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Character/SCGBaseCharacter.h"
#include "SCGPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;

struct FInputActionValue;

UCLASS(Abstract)
class ASCGPlayerCharacter : public ASCGBaseCharacter
{
    GENERATED_BODY()

public:
    ASCGPlayerCharacter();

private:
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    USpringArmComponent* CameraBoom;
    UPROPERTY(EditDefaultsOnly, Category = "Components")
    UCameraComponent* FollowCamera;

    UPROPERTY(EditDefaultsOnly, Category = "Settings | Input")
    UInputAction* MoveAction;
    UPROPERTY(EditDefaultsOnly, Category = "Settings | Input")
    UInputAction* LookAction;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
};
