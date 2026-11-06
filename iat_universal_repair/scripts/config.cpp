class CfgPatches
{
	class IAT_Universal_Repair_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Universal_Repair
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Universal Repair";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_universal_repair/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_universal_repair/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_universal_repair/scripts/5_mission" };
			};
		};
	};
};