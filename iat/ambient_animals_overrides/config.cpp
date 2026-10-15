class CfgPatches
{
	class IAT_AmbientAnimals_Overrides
	{
		requiredAddons[] = { "DayZ_Otter" };
	};
};

class CfgVehicles
{
	class Edible_Base;

	class OtterSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
};