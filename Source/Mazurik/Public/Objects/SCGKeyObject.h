// Mazurik V.V project
#pragma once

#include "CoreMinimal.h"
#include "Objects/SCGInteractObject.h"
#include "Engine/DataTable.h"
#include "Helpers/SCGKeyHelper.h"
#include "SCGKeyObject.generated.h"

UCLASS()
class MAZURIK_API ASCGKeyObject : public ASCGInteractObject
{
	GENERATED_BODY()

public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual bool StartTheAction() override;

private:
	UPROPERTY(EditAnywhere, Category = "Settings", meta = (RowType = "KeyInfoBase"))
	FDataTableRowHandle KeyRow;
};
