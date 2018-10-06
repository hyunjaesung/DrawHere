// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include"Stroke.h"


#include "HandController.generated.h"

UCLASS()
class DRAWHERE_API AHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AHandController();
	void TriggerPressed();
	void TriggerReleased();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

private:
	//config
	UPROPERTY(EditAnywhere)
		TSubclassOf<AStroke> StrokeClass;


	//Component
	UPROPERTY(VisibleAnywhere)
		UMotionControllerComponent*MotionContorller;

	//State

	AStroke * CurrentStroke;
	
	
};