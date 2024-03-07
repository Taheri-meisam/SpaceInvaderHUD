// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "PhysicActor.generated.h"

UCLASS()
class WEEK6SPACEINVADER_API APhysicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysicActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Mesh Physics")
	UStaticMeshComponent* MyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh Physics")
	float forceValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh Physics")
	class UPhysicsConstraintComponent* Constraint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh Physics")
	int direction = 1;
};
