class CfgPatches
{
	class IAT_Smelting_Metallurgy_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Smelting_Metallurgy
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Smelting Metallurgy";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_smelting_metallurgy/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_smelting_metallurgy/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_smelting_metallurgy/scripts/5_mission" };
			};
		};
	};
};