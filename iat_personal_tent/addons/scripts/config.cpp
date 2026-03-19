class CfgPatches
{
	class IAT_Personal_Tent_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Personal_Tent
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Personal Tent";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_personal_tent/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_personal_tent/scripts/5_mission" };
			};
		};
	};
};