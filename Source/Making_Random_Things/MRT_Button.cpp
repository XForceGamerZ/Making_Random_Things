// Fill out your copyright notice in the Description page of Project Settings.


#include "MRT_Button.h"
#include "Components/BoxComponent.h"

// Sets default values
AMRT_Button::AMRT_Button()
{
	
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot")); // Create Default Scene Root.
	
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(DefaultSceneRoot);
	
	Button_Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Base")); // Create Button Base.
	Button_Base->SetupAttachment(DefaultSceneRoot); // Attach To Default Scene Root.
	
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button")); // Create Button.
	Button->SetupAttachment(Button_Base); // Attach To Button Base.
	
	
	OriginalLocation = Button->GetRelativeLocation(); // Set Original Location
	NewLocation = Button->GetRelativeLocation() + FVector(0.0f, 0.0f, -7.0f); // Set New Location
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMRT_Button::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMRT_Button::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMRT_Button::Press(float Alpha)
{
	Button->SetRelativeLocation(FMath::Lerp(OriginalLocation, NewLocation, Alpha));
}

void AMRT_Button::Release(float Alpha)
{
	Button->SetRelativeLocation(FMath::Lerp(NewLocation, OriginalLocation, Alpha));
}