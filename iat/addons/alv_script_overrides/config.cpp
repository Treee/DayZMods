class CfgPatches
{
	class IAT_DZ_ALV_Script_ConfigOverrides
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_DZ_ALV_Script_ConfigOverrides_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "ALV Basic Script Override";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/alv_script_overrides/scripts/4_world" };
			};
		};
	};
};