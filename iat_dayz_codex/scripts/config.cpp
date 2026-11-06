class CfgPatches
{
	class IAT_DayZ_Codex_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_DayZ_Codex
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee DayZ Codex";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_dayz_codex/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_dayz_codex/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_dayz_codex/scripts/5_mission" };
			};
		};
	};
};