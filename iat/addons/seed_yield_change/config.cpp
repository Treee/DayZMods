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
		dependencies[] = { "Game","World" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "IAT/seed_yield_change/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/seed_yield_change/scripts/4_world" };
			};
		};
	};
};