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
				value = "";
				files[] = { "iat_collectibles/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_collectibles/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_collectibles/scripts/5_mission" };
			};
		};
	};
};