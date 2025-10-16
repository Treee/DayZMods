class CfgPatches
{
	class IAT_Roll_Tables_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Roll_Tables
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Roll Tables";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_roll_tables/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_roll_tables/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_roll_tables/scripts/5_mission" };
			};
		};
	};
};