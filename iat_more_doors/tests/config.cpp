class CfgPatches
{
	class IAT_MoreDoors_Tests
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = { "IAT_MoreDoors_Scripts", "IAT_MoreDoors_Camping" };
	};
};
class CfgMods
{
	class IAT_MoreDoors_Tests
	{
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_more_doors/tests/scripts/4_world" };
			};
		};
	};
};
