class CfgPatches
{
	class IAT_PluginRepair_Fix
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_PluginRepair_Fix
	{
		type = "mod";
		author = "ItsATreee";
		name = "Plugin Repair Fix";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/pluginrepair_fix/scripts/4_world" };
			};
		};
	};
};