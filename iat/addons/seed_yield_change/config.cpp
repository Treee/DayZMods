class CfgPatches
{
	class IAT_SeedYieldChange
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_SeedYieldChange
	{
		type = "mod";
		author = "ItsATreee";
		name = "Seed Yield Changes";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/seed_yield_change/scripts/4_world" };
			};
		};
	};
};