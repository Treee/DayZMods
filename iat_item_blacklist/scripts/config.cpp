class CfgPatches
{
	class IAT_Item_Blacklist_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Item_Blacklist
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Item Blacklist";
		dependencies[] = { "Game","Mission" };
		storageVersion = 1;
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"iat_item_blacklist/scripts/3_game"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_item_blacklist/scripts/5_mission" };
			};
		};
	};
};