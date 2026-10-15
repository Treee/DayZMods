class CfgPatches
{
	class IAT_SurvivorAnimations_Overrides
	{
		requiredAddons[] = { "SurvivorAnims" };
	};
};

class CfgMods
{
	class IAT_SurvivorAnimations_Overrides
	{
		type = "mod";
		author = "ItsATreee";
		name = "Survivor Animations Overrides";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat\survivor_animations_overrides\scripts\4_world" };
			};
		};
	};
};