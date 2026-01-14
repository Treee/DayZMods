class CfgPatches
{
	class IAT_Display_Case_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Display_Case
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Display Case";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_display_case/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_display_case/scripts/5_mission" };
			};
		};
	};
};