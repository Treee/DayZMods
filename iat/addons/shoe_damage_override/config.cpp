class CfgPatches
{
	class IAT_Shoe_Damage_Override
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts" };
	};
};
class CfgMods
{
	class IAT_Shoe_Damage_Override
	{
		type = "mod";
		author = "ItsATreee";
		name = "Shoe Damage Override";
		dependencies[] = { "Game" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "IAT/shoe_damage_override/scripts/3_game" };
			};
		};
	};
};