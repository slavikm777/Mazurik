// Mazurik V.V project

using UnrealBuildTool;
using System.Collections.Generic;

public class MazurikTarget : TargetRules
{
	public MazurikTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Mazurik" } );
	}
}
