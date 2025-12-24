class CfgPatches
{
	class IAT_Smoke_Signals_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Smoke_Signals
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Smoke Signals";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_smoke_signals/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_smoke_signals/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_smoke_signals/scripts/5_mission" };
			};
		};
	};
};