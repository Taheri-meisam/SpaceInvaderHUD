// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Enemy.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	Cast<UShapeComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this,&ABullet::OnOverlap);


/* Cast<UShapeComponent>(RootComponent):
This is attempting to cast the RootComponent to a UShapeComponent. 
A cast is a way to tell the compiler to treat a variable as if it were of a different type.
*/
/*
AddDynamic(this, &ABullet::OnOverlap): This adds a dynamic delegate binding, meaning that when the OnComponentBeginOverlap event is triggered,
it will call the OnOverlap function of the ABullet object (this).
The &ABullet::OnOverlap is a pointer to the member function OnOverlap of the ABullet class.
*/

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector()*Speed * DeltaTime;
	SetActorLocation(NewLocation);
	TimeLived+=DeltaTime;

	if (TimeLived > TimeBeforeDestroy)
	{
		this->Destroy();
	} 

}

void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult){

UE_LOG(LogTemp,Warning,TEXT(" Overlapped"));
// if it hits enemy destroy enemy and this actor 
if(OtherActor->IsA(AEnemy::StaticClass()))
    {
        Cast<AEnemy>(OtherActor)->ImHit(); //OtherActor->Destroy();
        //PartikkelFX:
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BulletFireFX, GetTransform(), true);
        
        //SoundFX
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), BulletFireSound, GetActorLocation());

        //Destroy Bullet:
        Destroy();
    }


}