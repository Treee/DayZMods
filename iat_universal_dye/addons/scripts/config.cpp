class CfgPatches
{
	class IAT_Universal_Dye_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Universal_Dye
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Universal Dye";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_universal_dye/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_universal_dye/scripts/5_mission" };
			};
		};
	};
};