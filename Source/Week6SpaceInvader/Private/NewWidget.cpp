// Fill out your copyright notice in the Description page of Project Settings.


#include "NewWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UNewWidget::SetEnemy(float CurrentEnemy, float MaxEnemy)
{
	if (EnemyBar)
	{
		EnemyBar->SetPercent(CurrentEnemy / MaxEnemy);
	}
}

void UNewWidget::SetAmmo(float CurrentAmmo, float MaxAmmo)
{

	if (AmmoBar)
	{
		AmmoBar->SetPercent(CurrentAmmo / MaxAmmo);
	}
}
