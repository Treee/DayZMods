class CfgPatches
{
	class IAT_Liquid_Fix
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Liquid_Fix
	{
		type = "mod";
		author = "ItsATreee";
		name = "Liquid Fix";
		dependencies[] = { "Game", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat/liquid_fix/scripts/3_game" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat/liquid_fix/scripts/5_mission" };
			};
		};
	};
};