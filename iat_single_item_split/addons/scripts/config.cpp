class CfgPatches
{
	class IAT_Single_Item_Split_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Single_Item_Split
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Single Item Split";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_single_item_split/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_single_item_split/scripts/5_mission" };
			};
		};
	};
};