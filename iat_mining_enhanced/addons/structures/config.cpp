class CfgPatches
{
	class IAT_Mining_Structures
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgVehicles
{
	class HouseNoDestruct;

	class IAT_MiningSegment_Colorbase : HouseNoDestruct
	{
		scope = 0;
		displayName = "Tunnel";
		descriptionShort = "A rock tunnel";
		model = "iat_mining_enhanced\structures\iat_miningsegment_junction.p3d";
		handheld = "false";
		physLayer = "item_large"; // give it collission
		debug_ItemCategory = 10;
		weight = 100000;
		itemSize[] = { 50, 50 };
		itemsCargoSize[] = { 0 , 0 };
		// hiddenSelections[] = { "zbytek"};
		// hiddenSelectionsTextures[] = { "DZ\gear\consumables\data\pile_of_planks_co.paa" };
	};

	class land_iat_miningsegment_entrance : IAT_MiningSegment_Colorbase
	{
		scope = 1;
		model = "iat_mining_enhanced\structures\iat_miningsegment_entrance.p3d";
	};
	class land_iat_miningsegment_junction : IAT_MiningSegment_Colorbase
	{
		scope = 1;
		model = "iat_mining_enhanced\structures\iat_miningsegment_junction.p3d";
	};
};