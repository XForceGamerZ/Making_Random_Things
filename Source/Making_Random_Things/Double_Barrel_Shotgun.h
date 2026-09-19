// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Double_Barrel_Shotgun.generated.h"

UCLASS()
class MAKING_RANDOM_THINGS_API ADouble_Barrel_Shotgun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADouble_Barrel_Shotgun();

protected:
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun")
	USceneComponent* RootScene;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun")
	UStaticMeshComponent* Body;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun")
	UStaticMeshComponent* Barrel;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun")
	UStaticMeshComponent* Trigger_Hold;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun")
	UStaticMeshComponent* Trigger;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun", meta = (DisplayName = "B1 12 Gauge Ammo"))
	UStaticMeshComponent* Ammo1;
	
	UPROPERTY(EditAnywhere, Category = "DB_Shotgun", meta = (DisplayName = "B2 12 Gauge Ammo"))
	UStaticMeshComponent* Ammo2;
	
	
	UFUNCTION(BlueprintCallable, Category = "DB_Shotgun_Controls")
	bool Shoot(USceneComponent* Component_To_Attached_To, float Radius, float Range, ECollisionChannel TraceChannel, bool LineVisible);
	
	UFUNCTION(BlueprintCallable, Category = "DB_Shotgun_Controls")
	void Equip(float Alpha);
	
	UFUNCTION(BlueprintCallable, Category = "DB_Shotgun_Controls")
	void UnEquip(float Alpha);
	
	
	void MakeDB_Shotgun_Visible() const;
	
	void MakeDB_Shotgun_Invisible() const;
	
	
	FRotator OGRotation;
	FRotator NewRotation;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
