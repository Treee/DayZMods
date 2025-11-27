class CfgPatches
{
	class IAT_DZ_ConfigOverrides_Gear_Food
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Food"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;

	//==================================================== VANILLA OVERRIDE
	class BoxCerealCrunchin : Edible_Base
	{
		canBeSplit = 1;
		weight = 2;
		itemSize[] = { 2,2 };
	};
	class SmallGuts : Edible_Base
	{
		weight = 8;
	};
	class Guts : Edible_Base
	{
		weight = 7;
		canBeSplit = 1;
		itemSize[] = { 2,1 };
	};
	class BakedBeansCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class BakedBeansCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class PeachesCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class PeachesCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class TacticalBaconCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class TacticalBaconCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class SpaghettiCan : Edible_Base
	{
		itemSize[] = { 1,2 };
	};
	class SpaghettiCan_Opened : Edible_Base
	{
		itemSize[] = { 1,2 };
	};


	// ====================== WHITE MEAT
	class HumanSteakMeat : Edible_Base
	{
		displayName = "White Meat";
		descriptionShort = "A cut of white meat.";
		model = "\dz\gear\food\meat_breast.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_breast_raw_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_dried_CO.paa", "dz\gear\food\data\meat_breast_burnt_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_breast_raw.rvmat", "dz\gear\food\data\meat_breast_baked.rvmat", "dz\gear\food\data\meat_breast_boiled.rvmat", "dz\gear\food\data\meat_breast_dried.rvmat", "dz\gear\food\data\meat_breast_burnt.rvmat", "dz\gear\food\data\meat_breast_rotten.rvmat" };
	};
	class BoarSteakMeat : Edible_Base
	{
		displayName = "White Meat";
		descriptionShort = "A cut of white meat.";
		model = "\dz\gear\food\meat_breast.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_breast_raw_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_dried_CO.paa", "dz\gear\food\data\meat_breast_burnt_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_breast_raw.rvmat", "dz\gear\food\data\meat_breast_baked.rvmat", "dz\gear\food\data\meat_breast_boiled.rvmat", "dz\gear\food\data\meat_breast_dried.rvmat", "dz\gear\food\data\meat_breast_burnt.rvmat", "dz\gear\food\data\meat_breast_rotten.rvmat" };
	};
	class PigSteakMeat : Edible_Base
	{
		displayName = "White Meat";
		descriptionShort = "A cut of white meat.";
		model = "\dz\gear\food\meat_breast.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_breast_raw_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_baked_CO.paa", "dz\gear\food\data\meat_breast_dried_CO.paa", "dz\gear\food\data\meat_breast_burnt_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_breast_raw.rvmat", "dz\gear\food\data\meat_breast_baked.rvmat", "dz\gear\food\data\meat_breast_boiled.rvmat", "dz\gear\food\data\meat_breast_dried.rvmat", "dz\gear\food\data\meat_breast_burnt.rvmat", "dz\gear\food\data\meat_breast_rotten.rvmat" };
	};

	// ====================== RED MEAT
	class GoatSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class MouflonSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class DeerSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class ReindeerSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class WolfSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class BearSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class CowSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class SheepSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};
	class FoxSteakMeat : Edible_Base
	{
		displayName = "Red Meat";
		descriptionShort = "A cut of red meat.";
		model = "\dz\gear\food\meat_steak.p3d";
		itemSize[] = { 1,2 };
		hiddenSelections[] = { "cs_raw" };
		hiddenSelectionsTextures[] = { "dz\gear\food\data\meat_steak_raw_CO.paa", "dz\gear\food\data\meat_steak_baked_CO.paa", "dz\gear\food\data\meat_steak_boiled_co.paa", "dz\gear\food\data\meat_steak_dried_CO.paa", "dz\gear\food\data\meat_steak_burned_CO.paa" };
		hiddenSelectionsMaterials[] = { "dz\gear\food\data\meat_steak_raw.rvmat", "dz\gear\food\data\meat_steak_baked.rvmat", "dz\gear\food\data\meat_steak_boiled.rvmat", "dz\gear\food\data\meat_steak_dried.rvmat", "dz\gear\food\data\meat_steak_burnt.rvmat", "dz\gear\food\data\meat_steak_rotten.rvmat" };
	};

	class Banana : Edible_Base
	{
		displayName = "Banana";
		descriptionShort = "A banana.";
	};
	class Orange : Edible_Base
	{
		displayName = "Orange";
		descriptionShort = "An orange.";
	};
	class Kiwi : Edible_Base
	{
		displayName = "Kiwi";
		descriptionShort = "A kiwi.";
	};
	class Cannabis : Edible_Base
	{
		displayName = "Cannabis";
		descriptionShort = "A bud of cannabis.";
	};
};