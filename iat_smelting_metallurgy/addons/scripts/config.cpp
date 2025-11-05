class CfgPatches
{
	class IAT_Smelting_Metallurgy_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Smelting_Metallurgy
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Smelting Metallurgy";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_smelting_metallurgy/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_smelting_metallurgy/scripts/5_mission" };
			};
		};
	};
};