class CfgPatches
{
	class IAT_Dynamic_Radio_Range_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Dynamic_Radio_Range
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Dynamic Radio Range";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_dynamic_radio_range/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_dynamic_radio_range/scripts/5_mission" };
			};
		};
	};
};