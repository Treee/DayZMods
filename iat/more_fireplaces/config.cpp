class CfgPatches
{
	class IAT_MoreFireplaces
	{
		requiredAddons[] = { "DZ_Data","DZ_Scripts", "DZ_Gear_Camping" };
	};
};
class CfgMods
{
	class IAT_MoreFireplaces
	{
		type = "mod";
		author = "ItsATreee";
		name = "More Fireplaces";
		dependencies[] = { "Game","World" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "IAT/more_fireplaces/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "IAT/more_fireplaces/scripts/4_world" };
			};
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;

	class IAT_Bonfire : HouseNoDestruct
	{
		scope = 2;
		model = "\DZ\gear\camping\bonfire.p3d";
	};
};