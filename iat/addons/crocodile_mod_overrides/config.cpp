class CfgPatches
{
	class IAT_Crocodile_Overrides
	{
		requiredAddons[] = { "DayZ_Croco" };
	};
};

class CfgVehicles
{
	class Edible_Base;

	class CrocodileSteakMeat : Edible_Base
	{
		displayName = "White Meat";
		descriptionShort = "A cut of white meat.";
		model = "\dz\gear\food\meat_breast.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_breast_raw_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_dried_CO.paa", "dz\gear\food\data\meat_breast_burnt_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_breast_raw.rvmat", "dz\gear\food\data\meat_breast_baked.rvmat", "dz\gear\food\data\meat_breast_boiled.rvmat", "dz\gear\food\data\meat_breast_dried.rvmat", "dz\gear\food\data\meat_breast_burnt.rvmat", "dz\gear\food\data\meat_breast_rotten.rvmat" };
	};
};