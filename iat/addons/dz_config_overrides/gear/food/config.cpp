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


	class HumanSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class GoatSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class MouflonSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class BoarSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class PigSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class DeerSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class ReindeerSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class WolfSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class BearSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class CowSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class SheepSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
	};
	class FoxSteakMeat : Edible_Base
	{
		displayName = "Meat";
		descriptionShort = "A cut of meat.";
		model = "\dz\gear\food\human_meat.p3d";
		itemSize[] = { 1,2 };
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