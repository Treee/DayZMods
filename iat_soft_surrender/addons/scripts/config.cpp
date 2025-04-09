class CfgPatches
{
	class IAT_Soft_Surrender_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Soft_Surrender
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Soft Surrender";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_soft_surrender/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_soft_surrender/scripts/5_mission" };
			};
		};
	};
};