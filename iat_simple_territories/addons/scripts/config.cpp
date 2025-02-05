class CfgPatches
{
	class IAT_Simple_Territories_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", };
	};
};
class CfgMods
{
	class IAT_Simple_Territories
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Simple Territories";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_simple_territories/scripts/4_world" };
			};
		};
	};
};