class CfgPatches
{
	class IAT_Codelock_Consumables
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Gear_Consumables" };
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class IAT_DyeVial_ColorBase : Inventory_Base
	{
		displayName = "Vial of Dye";
		descriptionShort = "A small vial of dye used to modify the color of clothing.";
		model = "\dz\gear\consumables\Chemlight.p3d";
		itemSize[] = { 1, 2 };
		weight = 30;
		weightPerQuantityUnit = 0;
		stackedUnit = "w";
		quantityBar = 1;
		varQuantityInit = 100;
		varQuantityMin = 0;
		varQuantityMax = 100;
		varQuantityDestroyOnMin = 1;
		rotationFlags = 17;
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "dz\gear\consumables\data\chemlight_ca.paa" };
		soundImpactType = "plastic";
	};

	class IAT_DyeVial_Basic : IAT_DyeVial_ColorBase
	{
		scope = 2;
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "dz\gear\consumables\data\chemlight_ca.paa" };
	};
};