// Fill out your copyright notice in the Description page of Project Settings.
//hi
//s
#include "MyCharacterC.h"
#include<cstring>
#include<thread>
using namespace std;
#pragma warning(disable:4996)


// Sets default values
AMyCharacterC::AMyCharacterC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacterC::BeginPlay()
{
	Super::BeginPlay();
	Connections();
}
int AMyCharacterC::Connections() {
	
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
		return 1;
	}

	
	
	int size = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("77.121.173.140");
	addr.sin_port = htons(8080);
	addr.sin_family = AF_INET;
	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
		return 1;
	}
	UE_LOG(LogTemp, Warning, TEXT("Connection"));
	thread th(clientHandel);
	th.detach();

	return 0;
}
// Called every frame
void AMyCharacterC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyCharacterC::clientHandel() {
	char msg[256];
	char tampname[40];
	FString name;
	while (true) {
		recv(Connection, tampname, sizeof(tampname), NULL);
		recv(Connection, msg, sizeof(msg), NULL);
		name = "Name:" + tampname + " Message: "+msg;
		UE_LOG(LogTemp, Warning, TEXT(name));

	}
}
// Called to bind functionality to input
void AMyCharacterC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

