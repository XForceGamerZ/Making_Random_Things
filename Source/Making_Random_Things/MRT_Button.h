// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MRT_Button.generated.h"

UCLASS()
class MAKING_RANDOM_THINGS_API AMRT_Button : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMRT_Button();

protected:
	
	UPROPERTY(EditAnywhere, Category = "Button")
	USceneComponent* DefaultSceneRoot;
	
	UPROPERTY(EditAnywhere, Category = "Button")
	UStaticMeshComponent* Button_Base;
	
	UPROPERTY(EditAnywhere, Category = "Button")
	UStaticMeshComponent* Button;
	
	UPROPERTY(EditAnywhere, Category = "Button")
	UBoxComponent* Collision;
	
	
	UFUNCTION(BlueprintCallable, Category = "Button Control")
	void Press(float Alpha);
	
	UFUNCTION(BlueprintCallable, Category = "Button Control")
	void Release(float Alpha);
	
	
	FVector OriginalLocation;
	FVector NewLocation;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};