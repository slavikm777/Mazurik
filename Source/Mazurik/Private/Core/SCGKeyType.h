// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "SCGKeyType.generated.h"

USTRUCT(BlueprintType)
struct FKeyInfoBase : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    int KeyID;

    UPROPERTY(EditDefaultsOnly)
    FText Name;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh* StaticMesh;

    UPROPERTY(EditDefaultsOnly)
    bool Universal;

    bool operator==(const FKeyInfoBase& OtherKey) const
    {
        return KeyID == OtherKey.KeyID && Universal == OtherKey.Universal &&
               Name.ToString() == OtherKey.Name.ToString();
    }
};
