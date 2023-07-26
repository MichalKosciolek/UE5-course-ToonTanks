// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Turret.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if(DeadActor == Tank)
    {
        Tank->HandleDestruction();
        auto PlayerController = Tank->GetTankPlayerController();
        if (PlayerController)
        {
            Tank->DisableInput(PlayerController);
            PlayerController->bShowMouseCursor = false;
        }
    }
    else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
    {
        DestroyedTurret->HandleDestruction();
    }
}

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
} 