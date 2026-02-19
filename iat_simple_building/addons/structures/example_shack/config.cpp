class CfgPatches
{
	class IAT_Simple_Building_Structures_ExampleShack
	{
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class IAT_BuildingStage_ColorBase;
	class IAT_BuildingStage_ExampleShack_0 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_0.p3d";
        hiddenSelections[]={"rope", "stick"};
        hiddenSelectionsTextures[]={"dz\gear\crafting\data\bp_rope_black_co.paa", "dz\gear\crafting\data\wooden_stick_co.paa"};
	};
	class IAT_BuildingStage_ExampleShack_1 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_1.p3d";
        hiddenSelections[]={"Int_Floor", "Outdoor_Floor"};
        hiddenSelectionsTextures[]={"iat_simple_building\structures\example_shack\data\Floors_Plain_CO.paa", "iat_simple_building\structures\example_shack\data\SinglePlanks_CO.paa"};
	};
	class IAT_BuildingStage_ExampleShack_2 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_2.p3d";
        hiddenSelections[]={"Int_Floor", "Outdoor_Floor", "Walls"};
        hiddenSelectionsTextures[]={"iat_simple_building\structures\example_shack\data\Floors_Plain_CO.paa", "iat_simple_building\structures\example_shack\data\SinglePlanks_CO.paa", "iat_simple_building\structures\example_shack\data\WoodWall_Unpainted_Dark_CO.paa"};
	};
	class IAT_BuildingStage_ExampleShack_3 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_3.p3d";
        hiddenSelections[]={"Int_Floor", "Outdoor_Floor", "Walls"};
        hiddenSelectionsTextures[]={"iat_simple_building\structures\example_shack\data\Floors_Plain_CO.paa", "iat_simple_building\structures\example_shack\data\SinglePlanks_CO.paa", "iat_simple_building\structures\example_shack\data\WoodWall_Unpainted_Dark_CO.paa"};
	};
	class IAT_BuildingStage_ExampleShack_4 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_4.p3d";
        hiddenSelections[]={"Int_Floor", "Outdoor_Floor", "Walls"};
        hiddenSelectionsTextures[]={"iat_simple_building\structures\example_shack\data\Floors_Plain_CO.paa", "iat_simple_building\structures\example_shack\data\SinglePlanks_CO.paa", "iat_simple_building\structures\example_shack\data\WoodWall_Unpainted_Dark_CO.paa"};
	};
	class IAT_BuildingStage_ExampleShack_5 : IAT_BuildingStage_ColorBase
	{
		scope = 2;
		model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_5.p3d";
        hiddenSelections[]={"Int_Floor", "Outdoor_Floor", "Walls", "Roof", "glass"};
        hiddenSelectionsTextures[]=
		{
			"iat_simple_building\structures\example_shack\data\Floors_Plain_CO.paa",
			"iat_simple_building\structures\example_shack\data\SinglePlanks_CO.paa",
			"iat_simple_building\structures\example_shack\data\WoodWall_Unpainted_Dark_CO.paa",
			"iat_simple_building\structures\example_shack\data\Roof_CO.paa",
			"iat_simple_building\structures\example_shack\data\Glass_CA.paa"
		};
	};
};
