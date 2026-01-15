class CfgPatches
{
	class IAT_Treasure_Hunts_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Treasure_Hunts
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Treasure Hunts";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_treasure_hunts/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_treasure_hunts/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_treasure_hunts/scripts/5_mission" };
			};
		};
	};
};