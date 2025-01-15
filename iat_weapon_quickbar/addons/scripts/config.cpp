class CfgPatches
{
	class IAT_Weapon_Quickbar_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Weapon_Quickbar
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Weapon Quickbar";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_weapon_quickbar/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_weapon_quickbar/scripts/5_mission" };
			};
		};
	};
};