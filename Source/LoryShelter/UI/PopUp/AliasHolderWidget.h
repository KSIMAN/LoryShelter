// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "AliasHolderWidget.generated.h"

/**
 * 
 */
class UAliasGameplay;
struct FInteractionInfo;

UENUM()
enum class EAliasIndex : uint8
{
	ITEM,
	PET
};

UCLASS()
class LORYSHELTER_API UAliasHolderWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//Shows alias for given index and updates info
	bool showAlias(const EAliasIndex& index, const FInteractionInfo& info);
	//Shows alias for given index
	bool showAlias(EAliasIndex index);
	//Hides alias for given index
	bool hideAlias(EAliasIndex index);

	//Creates alias of given type and push it to map if not created yet
	bool createAlias(const EAliasIndex& aliasType);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* aliasLayout;

	//Pointers for created aliases
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EAliasIndex, UAliasGameplay*> aliasses;

	//Aliases that must be created
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UAliasGameplay>> aliasSubClasses;


	virtual void NativeOnInitialized() override;
};
