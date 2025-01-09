class CfgPatches
{
	class IAT_Corrosive_BioGas_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Corrosive_BioGas
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Corrosive BioGas";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_corrosive_biogas/scripts/4_world" };
			};
		};
	};
};