class CfgPatches
{
	class IAT_Item_Blacklist_Tests
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = { "IAT_Item_Blacklist_Scripts" };
	};
};
class CfgMods
{
	class IAT_Item_Blacklist_Tests
	{
		type = "mod";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				files[] = { "iat_item_blacklist/tests/scripts/4_world" };
			};
		};
	};
};
