class CfgPatches
{
	class IAT_PlantGrowthChange
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_PlantGrowthChange
	{
		type = "mod";
		author = "ItsATreee";
		name = "Plant Growth Changes";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/plant_growth_change/scripts/4_world" };
			};
		};
	};
};