class CfgPatches
{
	class IAT_Simple_Carpentry_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Simple_Carpentry
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Simple Carpentry";
		dependencies[] = { "Game", "World", "Mission" };
		storageVersion = 1;
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_simple_carpentry/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_simple_carpentry/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_simple_carpentry/scripts/5_mission" };
			};
		};
	};
};