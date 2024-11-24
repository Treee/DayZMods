class CfgMods
{
	class SRP_Sakhal_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "Survivalists Sakhal";
		dir = "TheSurvivalists";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "TheSurvivalists/Sakhal/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "TheSurvivalists/Sakhal/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "TheSurvivalists/Sakhal/scripts/5_mission" };
			};
		};
	};
};

class CfgPatches
{
	class SRP_Sakhal_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
		};
	};
};