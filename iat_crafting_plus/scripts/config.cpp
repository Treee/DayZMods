class CfgPatches
{
	class IAT_Crafting_Plus_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Crafting_Plus
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Crafting Plus";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				files[] = { "iat_crafting_plus/scripts/3_game" };
			};
			class worldScriptModule
			{
				files[] = { "iat_crafting_plus/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_crafting_plus/scripts/5_mission" };
			};
		};
	};
};