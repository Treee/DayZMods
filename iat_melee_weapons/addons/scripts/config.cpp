class CfgPatches
{
	class IAT_Melee_Weapons_Scripts
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Melee_Weapons_Scripts
	{
		type = "mod";
		author = "ItsATreee";
		name = "ItsATreee Melee Weapons";
		dependencies[] = { "World" };
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "iat_melee_weapons/scripts/4_world" };
			};
		};
	};
};