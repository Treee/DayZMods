class CfgPatches
{
	class IAT_Firewood_Fuel_Override
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Firewood_Fuel_Override
	{
		type = "mod";
		author = "ItsATreee";
		name = "Firewood Fuel Override";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/firewood_fuel_override/scripts/4_world" };
			};
		};
	};
};