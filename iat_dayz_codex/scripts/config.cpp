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
				value = "";
				files[] = { "iat_dayz_codex/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_dayz_codex/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_dayz_codex/scripts/5_mission" };
			};
		};
	};
};