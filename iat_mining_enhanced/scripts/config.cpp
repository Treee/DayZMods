class CfgPatches
{
	class IAT_Mining_Enhanced_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Mining_Enhanced
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Mining Enhanced";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_mining_enhanced/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_mining_enhanced/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_mining_enhanced/scripts/5_mission" };
			};
		};
	};
};