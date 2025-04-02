// Mazurik V.V project

#include "Objects/SCGKeyObject.h"
#include "Character/Interfaces/SCGInteractInterface.h"

void ASCGKeyObject::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	check(KeyRow.DataTable);
	MeshComponent->SetStaticMesh(SCGKeyHelper::GetKeyStaticMesh(KeyRow.DataTable, KeyRow.RowName));
	Name = SCGKeyHelper::GetKeyName(KeyRow.DataTable, KeyRow.RowName);
}

bool ASCGKeyObject::StartTheAction()
{
	Super::StartTheAction();
	InteractInterface->TakeKey(KeyRow.RowName);
	Destroy();
	return true;
}
