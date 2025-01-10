class CfgPatches
{
	class IAT_Remove_BioZone_Teleport
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Remove_BioZone_Teleport
	{
		type = "mod";
		author = "ItsATreee";
		name = "Remove BioZone Teleport";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/remove_biozone_teleport/scripts/4_world" };
			};
		};
	};
};