class CfgPatches
{
	class IAT_Corrosive_BioGas_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "IAT_Enhanced_BioProtection_Scripts" };
	};
};
class CfgMods
{
	// workshop meta.cpp commit
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