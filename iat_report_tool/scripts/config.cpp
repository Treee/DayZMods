class CfgPatches
{
	class IAT_Report_Tool_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Report_Tool
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Report Tool";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_report_tool/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_report_tool/scripts/5_mission" };
			};
		};
	};
};