class CfgPatches
{
	class IAT_Universal_Codelock_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Universal_Codelock
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Universal Codelock";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_universal_codelock/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_universal_codelock/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_universal_codelock/scripts/5_mission" };
			};
		};
	};
};