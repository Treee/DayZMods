class CfgPatches
{
	class IAT_MapAnnotations_Scripts
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Navigation" };
	};
};
class CfgMods
{
	class IAT_MapAnnotations
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Map Annotations";
		dependencies[] = { "World", "Mission" };
		class defs
		{
			class worldScriptModule
			{
				files[] = { "iat_map_annotations/scripts/4_world" };
			};
			class missionScriptModule
			{
				files[] = { "iat_map_annotations/scripts/5_mission" };
			};
		};
	};
};
