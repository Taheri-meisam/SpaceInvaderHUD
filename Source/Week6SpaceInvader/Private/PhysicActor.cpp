// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicActor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"



// Sets default values
APhysicActor::APhysicActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a new object
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(RootComponent);

	// Enable physics on the mesh
	MyMesh->SetSimulatePhysics(true);
	forceValue = 20000.0f;
	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("MyConstraint"));


	/*
	add  "PhysicsCore"  to build.cs
	PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "PhysicsCore" });
	*/
	// Create a new Physics Material
	UPhysicalMaterial* MyMaterial = NewObject<UPhysicalMaterial>();

	// Set the friction value
	MyMaterial->Friction = 0.8f; // High friction

	// Set the restitution value
	MyMaterial->Restitution = 0.5f; // Low restitution (not very bouncy)

	// Apply the Physics Material to a mesh
	MyMesh->SetPhysMaterialOverride(MyMaterial);

	


}

// Called when the game starts or when spawned
void APhysicActor::BeginPlay()
{
	Super::BeginPlay();

	MyMesh->GetBodyInstance()->SetMassOverride(20.0f, true);
	MyMesh->SetEnableGravity(true);
	Constraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Locked, 0.f);

}


// Called every frame
void APhysicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//	MyMesh->AddForce(FVector(0, 0, -200));
	//MyMesh->AddForce(forceValue * FVector(0, 0, -200));

	FVector UPdirection = MyMesh->GetUpVector();
	MyMesh->AddForce(UPdirection *direction * forceValue * MyMesh->GetMass());
}

