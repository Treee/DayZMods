class CfgPatches
{
	class IAT_Dynamic_Traps_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Dynamic_Traps
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Dynamic Traps";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_dynamic_traps/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_dynamic_traps/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_dynamic_traps/scripts/5_mission" };
			};
		};
	};
};