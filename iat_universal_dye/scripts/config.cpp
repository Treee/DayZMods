class CfgPatches
{
	class IAT_Universal_Dye_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Universal_Dye
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Universal Dye";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_universal_dye/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_universal_dye/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_universal_dye/scripts/5_mission" };
			};
		};
	};
};