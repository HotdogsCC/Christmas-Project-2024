// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "Kismet/GameplayStatics.h"
#include "Storage/Nodes/FileEntry.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	//Get reference to the player
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Sets target position to player position
	TargetPosition = PlayerPawn->GetActorLocation();
	
	//Gets vector toward location
	FVector CurrentPos = GetActorLocation();
	FVector DirectionToTarget = TargetPosition - CurrentPos;
	DirectionToTarget.Z = 0; //As we only care about 2D following for now
	DirectionToTarget.Normalize();

	//Moves toward location
	CurrentPos += DirectionToTarget * Speed * DeltaTime;
	SetActorLocation(CurrentPos);
	

}

