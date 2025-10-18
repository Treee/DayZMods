class CfgPatches
{
	class IAT_Double_Armbands_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Double_Armbands
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Double Armbands";
		dependencies[] = { "World","Mission" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_double_armbands/scripts/4_world" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "iat_double_armbands/scripts/5_mission" };
			};
		};
	};
};