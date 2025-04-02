// Mazurik V.V project

#pragma once

#include "CoreMinimal.h"
#include "Objects/SCGObjectsOpeningUp.h"
#include "Engine/DataTable.h"
#include "Objects/Interfaces/SCGLockDoorInterface.h"
#include "SCGLockObjectsOpeningUp.generated.h"

UCLASS()
class MAZURIK_API ASCGLockObjectsOpeningUp : public ASCGObjectsOpeningUp, public ISCGLockDoorInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Settings", meta = (RowType = "KeyInfoBase"))
	FDataTableRowHandle KeyRow;

	bool TheRightKey(FName& KeyRowName);
	virtual bool OpenDoorWithLock(FName KeyRowName) override;
	virtual bool GetOpen() override;
};
