// Mazurik V.V project

#include "Objects/SCGLockObjectsOpeningUp.h"
#include "Helpers/SCGKeyHelper.h"

bool ASCGLockObjectsOpeningUp::TheRightKey(FName& KeyRowName)
{
    const FKeyInfoBase* Key = SCGKeyHelper::GetKeyInfo(KeyRow.DataTable, KeyRow.RowName);
    const FKeyInfoBase* Key2 = SCGKeyHelper::GetKeyInfo(KeyRow.DataTable, KeyRowName);
    return Key == Key2;
}

bool ASCGLockObjectsOpeningUp::OpenDoorWithLock(FName KeyRowName)
{
    if (TheRightKey(KeyRowName))
    {
        ASCGObjectsOpeningUp::StartTheAction();
        return true;
    }
    else
        UE_LOG(LogTemp, Warning, TEXT("ErrorKey"));
    return false;
}

bool ASCGLockObjectsOpeningUp::GetOpen()
{
    return ASCGObjectsOpeningUp::GetOpen();
}
