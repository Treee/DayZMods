class CfgPatches
{
	class IAT_Gas_Station_Changes_Scripts
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts", "IAT_Roll_Tables_Scripts", "IAT_Molotov_Grenades_Scripts" };
	};
};
class CfgMods
{
	class IAT_Gas_Station_Changes
	{
		type = "mod";
		author = "ItsATreee";
		name = "Gas Station Changes";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/gas_station_changes/scripts/4_world" };
			};
		};
	};
};