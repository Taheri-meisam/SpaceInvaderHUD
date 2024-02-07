// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPlayerController.h"



void AShipPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ScreenUiWidget) {
		ScreenUI = CreateWidget<UUserWidget>(this, ScreenUiWidget);
	}

	ScreenUI->AddToViewport();
	ScreenUI->SetVisibility(ESlateVisibility::Visible);


}