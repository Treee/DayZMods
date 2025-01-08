class CfgPatches
{
	class IAT_Enhanced_BioProtection_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Enhanced_BioProtection
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Enhanced BioProtection";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_enhanced_bioprotection/scripts/4_world" };
			};
		};
	};
};