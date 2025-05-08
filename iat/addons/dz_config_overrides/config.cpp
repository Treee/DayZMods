class CfgPatches
{
	class IAT_DZ_ConfigOverrides
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_DZ_ConfigOverrides_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "DZ Basic Script Override";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/dz_config_overrides/scripts/4_world" };
			};
		};
	};
};