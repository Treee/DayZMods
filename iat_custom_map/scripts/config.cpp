class CfgPatches
{
	class IAT_Custom_Map_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Custom_Map
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Custom Map";
		dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_custom_map/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_custom_map/scripts/5_mission" };
			};
		};
	};
};