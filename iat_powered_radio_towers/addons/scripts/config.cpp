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
				value = "";
				files[] = { "iat_powered_radio_towers/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_powered_radio_towers/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_powered_radio_towers/scripts/5_mission" };
			};
		};
	};
};