#pragma once

#include "SharingFunctions.h"
#include "SharingComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class USharingComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	

};
