// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealTanksArena_mk1EditorTarget : TargetRules
{
	public UnrealTanksArena_mk1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "UnrealTanksArena_mk1" } );
	}
}
