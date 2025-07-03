class CfgPatches
{
	class IAT_MoreDoors_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_MoreDoors
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee More Doors";
		dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_more_doors/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_more_doors/scripts/5_mission" };
			};
		};
	};
};