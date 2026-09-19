// Fill out your copyright notice in the Description page of Project Settings.


#include "Double_Barrel_Shotgun.h"
#include "DrawDebugHelpers.h"

// Sets default values
ADouble_Barrel_Shotgun::ADouble_Barrel_Shotgun()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(RootScene);
	
	Barrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
	Barrel->SetupAttachment(Body);
	
	Trigger_Hold = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trigger_Hold"));
	Trigger_Hold->SetupAttachment(Body);
	
	Trigger = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(Trigger_Hold);
	
	Ammo1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo1"));
	Ammo1->SetupAttachment(Barrel);
	
	Ammo2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ammo2"));
	Ammo2->SetupAttachment(Barrel);
	
	
	OGRotation = Body->GetRelativeRotation();
	NewRotation = Body->GetRelativeRotation() + FRotator(-100.0f,0.0f,0.0f);
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADouble_Barrel_Shotgun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADouble_Barrel_Shotgun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ADouble_Barrel_Shotgun::Shoot(USceneComponent* Component, float Radius, float Range, ECollisionChannel Trace_Channel, bool LineVisible)
{
	FHitResult HitResult;
	
	// Calculate Required Vector For Ray casting.
	
	
	// Get Component Location.
	const FVector Start = Component->GetComponentLocation();
	
	// Get Component Rotation.
	const FRotator ComponentRotation = Component->GetComponentRotation();
	
	// Get Component Forward Vector.
	const FVector ComponentForwardVector = ComponentRotation.Vector();
	
	// Calculate End Vector.
	const FVector End = (ComponentForwardVector * Range) + Start;
	
	bool bHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		Trace_Channel,
		FCollisionShape::MakeSphere(Radius)
		);
	
	if (LineVisible)
	{
		const FVector Direction = End - Start;
		const FVector Center = (Start + End) / 2.0f;

		const FColor Color = bHit ? FColor::Green : FColor::Red;

		DrawDebugCapsule(
			GetWorld(),
			Center,
			Direction.Size() / 2.0f,
			Radius,
			FRotationMatrix::MakeFromZ(Direction).ToQuat(),
			Color,
			false,
			1.0f
		);
		
	}
	
	return true;
}

void ADouble_Barrel_Shotgun::MakeDB_Shotgun_Visible() const
{
	RootScene->SetVisibility(true, true);
}

void ADouble_Barrel_Shotgun::MakeDB_Shotgun_Invisible() const
{
	RootScene->SetVisibility(false, true);
}

void ADouble_Barrel_Shotgun::Equip(float Alpha)
{
	
	MakeDB_Shotgun_Visible();
	Body->SetRelativeRotation(FMath::Lerp(NewRotation, OGRotation, Alpha));
	
}

void ADouble_Barrel_Shotgun::UnEquip(float Alpha)
{
	
	Body->SetRelativeRotation(FMath::Lerp(OGRotation, NewRotation, Alpha));
	if (Alpha >= 1)
	{
		MakeDB_Shotgun_Invisible();
	}
	
}