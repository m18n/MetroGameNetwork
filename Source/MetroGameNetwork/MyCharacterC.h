// Fill out your copyright notice in the Description page of Project Settings.
//vau
//b
#pragma once
#define WIN32_LEAN_AND_MEAN
#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterC.generated.h"

UCLASS()
class METROGAMENETWORK_API AMyCharacterC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterC();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Connection")
	int Connections();
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Connection")
	bool serveron;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player")
	int Armorr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player")
		int Heals;
private:
	SOCKET Connection;
	

};
