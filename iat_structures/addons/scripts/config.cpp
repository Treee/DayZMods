class CfgPatches
{
	class IAT_Structures_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Structures
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Structures";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_structures/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_structures/scripts/5_mission" };
			};
		};
	};
};