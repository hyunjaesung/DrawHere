// Fill out your copyright notice in the Description page of Project Settings.

#include "PaintingGrid.h"
#include "Components/SizeBox.h"
void UPaintingGrid::AddPainting()
{

	if (!PaintingGrid) return;
	
	
	UUserWidget * NewWidget = CreateWidget<UUserWidget>(GetWorld(), GridCardClass); // card which will add
	

	USizeBox*CardContainer = Cast<USizeBox>( PaintingGrid->GetChildAt(0)); // where to add

	if (!CardContainer) return;

	CardContainer->AddChild(NewWidget);

}
