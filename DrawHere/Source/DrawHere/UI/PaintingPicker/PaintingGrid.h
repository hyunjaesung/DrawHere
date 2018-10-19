// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/UniformGridPanel.h"

#include "PaintingGrid.generated.h"

/**
 * 
 */
UCLASS()
class DRAWHERE_API UPaintingGrid : public UUserWidget
{
	GENERATED_BODY()

public:

	void mock();
	UFUNCTION(BlueprintCallable)
	void AddPainting();

protected:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, meta = (BindWidget))
		UUniformGridPanel * PaintingGrid; // in blueprint you have to change the name of grid panel for matching
	
	
};
