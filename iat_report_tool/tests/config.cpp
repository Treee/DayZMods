class CfgPatches
{
	class IAT_ReportToolTests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Structures_Residential", "IAT_Report_Tool_Scripts" };
	};
};
class CfgMods
{
	class IAT_ReportToolTests
	{
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_report_tool/tests/scripts/4_world" };
			};
		};
	};
};
