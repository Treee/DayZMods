class CfgPatches
{
	class IAT_Universal_Dye_Gear_Drinks
	{
		requiredAddons[] = { "DZ_Data", "DZ_Gear_Drinks" };
	};
};
class CfgVehicles
{
	class Bottle_Base;

	// ----------------------  BASE GAME OVERRIDES
	class Canteen : Bottle_Base
	{
		rootClassName = "Canteen";
		colorVariants[] =
		{
			"Blue",
			"Pink",
			"Purple",
			"Neon",
			"Red",
		};
	};
};