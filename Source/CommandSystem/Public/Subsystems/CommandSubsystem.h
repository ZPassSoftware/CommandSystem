// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/CommandInterfaces.h"
#include "Subsystems/WorldSubsystem.h"

#include "CommandSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class COMMANDSYSTEM_API UCommandSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	protected:

	TArray<TScriptInterface<ICommand>> Commands;
	
	int32 Index;

	private:

	public:

	UCommandSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void AddCommand(const TScriptInterface<ICommand> Command);

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void UndoCommand();

	UFUNCTION(BlueprintCallable, Category = "Commands")
	void RedoCommand();

	UFUNCTION(BlueprintCallable, Category = "Commands")
	TArray<UObject*> GetCommandObjects();

	UFUNCTION(BlueprintPure, Category = "Commands")
	int32 GetNumberOfCommands() const;

	UFUNCTION(BlueprintPure, Category = "Commands")
	int32 GetIndex() const;

	protected:

	private:
	
};