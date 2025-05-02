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
				value = "";
				files[] = { "iat_crafting_plus/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_crafting_plus/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_crafting_plus/scripts/5_mission" };
			};
		};
	};
};