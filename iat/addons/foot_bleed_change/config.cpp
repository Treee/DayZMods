class CfgPatches
{
	class IAT_Foot_Bleed_Change
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Foot_Bleed_Change
	{
		type = "mod";
		author = "ItsATreee";
		name = "Foot Bleed Change";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat/foot_bleed_change/scripts/4_world" };
			};
		};
	};
};