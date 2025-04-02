// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"

class MAZURIK_API SCGDataTableHelper
{
public:
    static const FString& GetContextString();

    template <class T> static T* FindRow(const UDataTable* DataTable, const FName& RowName)
    {
        check(DataTable);
        return DataTable->FindRow<T>(RowName, ContextString, true);
    }

    template <class T> static T* GetFirstRow(const UDataTable* DataTable)
    {
        check(DataTable);
        TArray<T*> Rows;
        DataTable->GetAllRows<T>(ContextString, Rows);
        check(Rows.Num() > 0);
        return Rows[0];
    }

    template <class T> static void GetAllRows(const UDataTable* DataTable, TArray<T*>& Rows)
    {
        check(DataTable);
        DataTable->GetAllRows<T>(ContextString, Rows);
    }

    static TArray<FName> GetRowNames(const UDataTable* DataTable) 
    {
        check(DataTable);
        return DataTable->GetRowNames();
    };
    static bool RowExists(const UDataTable* DataTable, const FName& RowName) 
    {
        check(DataTable);
        return DataTable->GetRowNames().Contains(RowName);
    };

private:
    static const FString ContextString;
};
