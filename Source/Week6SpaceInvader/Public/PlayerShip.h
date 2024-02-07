// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Blueprint/UserWidget.h"
#include "PlayerShip.generated.h"

UCLASS()
class WEEK6SPACEINVADER_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	// Setting up the Player Mesh 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
UStaticMeshComponent* PlayerMesh = nullptr;


	// Setting up the spring Arm that can be attached to camera 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USpringArmComponent* SpringArm {nullptr};

// Camera 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
UCameraComponent* Camera = nullptr;

// Movemenet speed 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
float Speed = 5.f;
	//Number of available Ammos // start with 30
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
int Ammo = 30;

	//Max number of Ammos 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
int MaxAmmo = 30;

	// USoundBase for shooting sound 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USoundBase* ShootingSound = nullptr;

	//UShapeComponent for creating a collisionBox 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
UShapeComponent* CollisionBox =nullptr;

	//reloding sound 
UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PlayerMesh")
USoundBase* ReloadingSound = nullptr;

	// Actors to spawn - subclass of AActor 
UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess = "true"));
TSubclassOf<AActor> ActorToSpawn;

	// Enemies 
UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess = "true"));
TSubclassOf<AActor> ActorEney;

	// UWidgetComponent to assign the AMO UI widget 
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
class UWidgetComponent* AmoUIComp;
	// UUserWidget for screen widget 
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
TSubclassOf<UUserWidget> ScreenUiWidget;

	// Main widget pointer 
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
UUserWidget* MainWidgetPtr = nullptr;
	
//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
//class UWidgetComponent* MainUiComp;

void Reload();

void Shoot();



UFUNCTION(BlueprintCallable)
void ResetLocation() const;


UFUNCTION(BlueprintCallable)
int RetMaxAmo();

UFUNCTION(BlueprintCallable)
int RetAmmo();


bool InContact;

protected: 
	void ResetGame();
	bool bEnemyDied = false;
	void SetDead();
private:
FVector InitLocation = FVector::ZeroVector;


void MoveXAxis(float Value);
void MoveYAxis(float Value);


void Dash();
float XValue = 0.f;
float YValue = 0.f;
float DashTimer = 0.f;


UFUNCTION()
void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent,
                        int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
friend class AWeek6SpaceInvaderGameModeBase;

};

