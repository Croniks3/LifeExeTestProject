// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LifeExeTestProjectTarget : TargetRules
{
	public LifeExeTestProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		
		ExtraModuleNames.Add("LifeExeTestProject");
	}
}
