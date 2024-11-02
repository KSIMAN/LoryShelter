// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LoryShelter : ModuleRules
{
	public LoryShelter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "NavigationSystem" });
	}
}