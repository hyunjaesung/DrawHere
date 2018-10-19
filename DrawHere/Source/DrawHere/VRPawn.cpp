// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPawn.h"
#include "Engine/World.h"
#include "Engine/Classes/Components/InputComponent.h"

AVRPawn::AVRPawn()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(VRRoot);
}


void AVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
	UPainterSaveGame*Painting = UPainterSaveGame::Create(); 

	if (Painting && Painting->Save())// save() doesn't make first save
	{
		
		CurrentSlotName = Painting->GetSlotName();

	}

	if (PaintBrushHandControllerClass)
	{
		RightPaintBrushHandController = GetWorld()->SpawnActor<AHandControllerBase>(PaintBrushHandControllerClass);
		RightPaintBrushHandController->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);

	}

	
}


void AVRPawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVRPawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVRPawn::RightTriggerReleased);
	PlayerInputComponent->BindAction(TEXT("Save"), EInputEvent::IE_Released, this, &AVRPawn::Save);
	PlayerInputComponent->BindAction(TEXT("Load"), EInputEvent::IE_Released, this, &AVRPawn::Load);
}

void AVRPawn::Save()
{
	UPainterSaveGame * Painting = UPainterSaveGame::Load(CurrentSlotName);

	if (Painting)
	{
		Painting->SetState("SaveWorld");
		Painting->SerializeFromWorld(GetWorld());
		Painting->Save();
		UE_LOG(LogTemp, Warning, TEXT("ThisisSave"));
	}

	
}

void AVRPawn::Load()
{
	UPainterSaveGame * Painting = UPainterSaveGame::Load(CurrentSlotName);
	if (Painting)
	{
		Painting->DeserializeToWorld(GetWorld());
		UE_LOG(LogTemp, Warning, TEXT("Painting State %s"), *Painting->GetState());// * Warning
		UE_LOG(LogTemp, Warning, TEXT("ThisisLoad"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NotFound"));
	}

}