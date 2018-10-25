// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HandControllerBase.h"
#include "Camera/CameraComponent.h"
#include "Saving/PainterSaveGame.h"


#include "VRPawn.generated.h"

UCLASS()
class DRAWHERE_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	
	AVRPawn();

protected:

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent
	(
		UInputComponent * PlayerInputComponent
	) override;

private :

	void RightTriggerPressed() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerPressed(); }
	void RightTriggerReleased() { if (RightPaintBrushHandController) RightPaintBrushHandController->TriggerReleased(); }

	void Save();
	//void Load(); to PaintingGameMode

	//Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AHandControllerBase> PaintBrushHandControllerClass;


	//Component
	UPROPERTY(VisibleAnywhere)
	USceneComponent*VRRoot;
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent*Camera;

	// Reference

	UPROPERTY()
		AHandControllerBase* RightPaintBrushHandController;

	


};
