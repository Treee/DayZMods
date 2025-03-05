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
				value = "";
				files[] = { "iat_universal_repair/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_universal_repair/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_universal_repair/scripts/5_mission" };
			};
		};
	};
};