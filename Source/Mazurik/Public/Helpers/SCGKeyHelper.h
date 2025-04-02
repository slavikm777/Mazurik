// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Helpers/SCGDataTableHelper.h"
#include "Core/SCGKeyType.h"

class MAZURIK_API SCGKeyHelper final
{
public:
    static const FKeyInfoBase* GetKeyInfo(const UDataTable* DTable, const FName& RowName)
    {
        return SCGDataTableHelper::FindRow<FKeyInfoBase>(DTable, RowName);
    };

    static const bool IsUniversal(const UDataTable* DTable, const FName& RowName)
    {
        const FKeyInfoBase* KeyInfo = GetKeyInfo(DTable, RowName);
        check(KeyInfo);
        return KeyInfo->Universal;
    }

    static UStaticMesh* GetKeyStaticMesh(const UDataTable* DTable, const FName& RowName)
    {
        const FKeyInfoBase* KeyInfo = GetKeyInfo(DTable, RowName);
        check(KeyInfo);
        return KeyInfo->StaticMesh;
    }

    static const int GetKeyID(const UDataTable* DTable, const FName& RowName)
    {
        const FKeyInfoBase* KeyInfo = GetKeyInfo(DTable, RowName);
        check(KeyInfo);
        return KeyInfo->KeyID;
    }

    static FText GetKeyName(const UDataTable* DTable, const FName& RowName)
    {
        const FKeyInfoBase* KeyInfo = GetKeyInfo(DTable, RowName);
        check(KeyInfo);
        return KeyInfo->Name;
    }
};
