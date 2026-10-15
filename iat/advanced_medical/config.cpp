class CfgPatches
{
	class IAT_AdvancedMedical
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_AdvancedMedical
	{
		type = "mod";
		author = "ItsATreee";
		name = "Advanced Medical";
		dependencies[] = { "Game","World" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "IAT/advanced_medical/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/advanced_medical/scripts/4_world" };
			};
		};
	};
};