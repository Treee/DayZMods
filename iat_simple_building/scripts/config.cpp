class CfgPatches
{
	class IAT_Simple_Building_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Simple_Building
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Simple Building";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_simple_building/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_simple_building/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_simple_building/scripts/5_mission" };
			};
		};
	};
};