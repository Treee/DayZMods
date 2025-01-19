class CfgPatches
{
	class IAT_BeardChanges
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_BeardChanges
	{
		type = "mod";
		author = "ItsATreee";
		name = "Beard Changes";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/beard_changes/scripts/4_world" };
			};
		};
	};
};