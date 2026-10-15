class CfgPatches
{
	class IAT_EnhancedMining_Frozen_Overrides_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "IAT_Mining_Enhanced_Scripts" };
	};
};
class CfgMods
{
	class IAT_EnhancedMining_Frozen_Overrides
	{
		type = "mod";
		author = "ItsATreee";
		name = "IAT Enhanced Mining Frozen Override";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat\enhanced_mining_frozen_addon\scripts" };
			};
		};
	};
};