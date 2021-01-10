// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealTanksArena_mk1Target : TargetRules
{
	public UnrealTanksArena_mk1Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "UnrealTanksArena_mk1" } );
	}
}
