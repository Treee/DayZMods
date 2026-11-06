class CfgPatches
{
	class IAT_Powered_Radio_Towers_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Powered_Radio_Towers
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Powered Radio Towers";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_powered_radio_towers/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_powered_radio_towers/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_powered_radio_towers/scripts/5_mission" };
			};
		};
	};
};