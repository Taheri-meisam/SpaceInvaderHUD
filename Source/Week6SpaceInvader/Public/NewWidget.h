// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NewWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class WEEK6SPACEINVADER_API UNewWidget : public UUserWidget
{


	GENERATED_BODY()

public:
	void SetEnemy(float CurrentEnemy, float MaxEnemy);

	/** Update HUD with current power. */
	void SetAmmo(float CurrentAmmo, float MaxAmmo);

	/** Widget to use to display current health. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* EnemyBar;

	/** Widget to use to display current power. */
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* AmmoBar;

	
};
