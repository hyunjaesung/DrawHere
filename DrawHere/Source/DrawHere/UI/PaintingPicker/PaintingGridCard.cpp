// Fill out your copyright notice in the Description page of Project Settings.


#include "PaintingGridCard.h"
#include "Saving/PainterSaveGame.h"
#include "Kismet/StereoLayerFunctionLibrary.h" 
#include "Kismet/GameplayStatics.h"

void UPaintingGridCard::SetPaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;

	SlotName->SetText(FText::FromString(PaintingName)); // text for user

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::CardButtonClicked); // binding method
}

void UPaintingGridCard::CardButtonClicked()
{
	UStereoLayerFunctionLibrary::ShowSplashScreen(); // for debug openlevel

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Canvas"), true, "SlotName=" + PaintingName);

	

}


void UPaintingGridCard::SetDeletePaintingName(FString NewPaintingName)
{
	PaintingName = NewPaintingName;

	SlotName->SetText(FText::FromString(PaintingName)); // text for user

	CardButton->OnClicked.AddDynamic(this, &UPaintingGridCard::DeleteCardButtonClicked); // binding method
}

void UPaintingGridCard::DeleteCardButtonClicked()
{
	UPainterSaveGame::Delete(PaintingName);

}