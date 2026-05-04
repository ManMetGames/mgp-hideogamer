// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UniGDEVMechanic : ModuleRules
{
	public UniGDEVMechanic(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UniGDEVMechanic",
			"UniGDEVMechanic/Variant_Horror",
			"UniGDEVMechanic/Variant_Horror/UI",
			"UniGDEVMechanic/Variant_Shooter",
			"UniGDEVMechanic/Variant_Shooter/AI",
			"UniGDEVMechanic/Variant_Shooter/UI",
			"UniGDEVMechanic/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
