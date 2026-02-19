class CfgPatches
{
	class IAT_Simple_Building_Structures
	{
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	/*
	*
	* Naming Convention: IAT_BuildingStage_BuildingName_Stage
	*
	*/
	class IAT_BuildingStage_ColorBase : HouseNoDestruct
    {
        scope=0;
		// this is so these "houseNoDestruct" actually save to the db on restarts
		storageCategory=1;
        displayName="Construction Site";
        descriptionShort="An area undergoing construction.";
        model="iat_simple_building\structures\example_shack\Sample_Shack_Tier_0.p3d";
        hiddenSelections[]={"rope", "stick"};
        hiddenSelectionsTextures[]={"dz\gear\crafting\data\bp_rope_black_co.paa", "dz\gear\crafting\data\wooden_stick_co.paa"};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=10000;
                    healthLevels[]={{1, {""}}, {0.7, {""}}, {0.5, {""}}, {0.3, {""}}, {0, {""}}};
                };
            };
        };
    };
};
