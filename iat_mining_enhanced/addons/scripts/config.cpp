class CfgPatches
{
	class IAT_Mining_Enhanced_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Mining_Enhanced
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Mining Enhanced";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_mining_enhanced/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_mining_enhanced/scripts/5_mission" };
			};
		};
	};
};