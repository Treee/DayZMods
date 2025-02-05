class CfgPatches
{
	class IAT_Simple_Territories_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Simple_Territories
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Simple Territories";
		dependencies[] = { "Game", "World" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_simple_territories/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_simple_territories/scripts/4_world" };
			};
			// class missionScriptModule
			// {
			// 	value = "";
			// 	files[] = { "iat_simple_territories/scripts/5_mission" };
			// };
		};

	};
};