// Mazurik V.V project

using UnrealBuildTool;
using System.Collections.Generic;

public class MazurikEditorTarget : TargetRules
{
	public MazurikEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Mazurik" } );
	}
}
