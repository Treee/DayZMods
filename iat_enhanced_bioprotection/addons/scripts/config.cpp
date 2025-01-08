class CfgPatches
{
	class IAT_Enhanced_BioProtection_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	// comment for workshop publish
	class IAT_Enhanced_BioProtection
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Enhanced BioProtection";
		dependencies[] = { "World","Mission" };
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