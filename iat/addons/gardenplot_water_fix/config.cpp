class CfgPatches
{
	class IAT_GardenPlot_WaterFix
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_GardenPlot_WaterFix
	{
		type = "mod";
		author = "ItsATreee";
		name = "GardenPlot Water Fix";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/gardenplot_water_fix/scripts/4_world" };
			};
		};
	};
};