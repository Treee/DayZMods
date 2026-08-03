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
		inputs = "iat_report_tool/scripts/inputs.xml";
		dependencies[] = { "Game", "World", "Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "iat_report_tool/scripts/3_game" };
			};
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