class CfgPatches
{
	class IAT_Collectibles_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Collectibles
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Collectibles";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_collectibles/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_collectibles/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_collectibles/scripts/5_mission" };
			};
		};
	};
};