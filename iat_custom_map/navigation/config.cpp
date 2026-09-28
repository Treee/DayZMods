class CfgPatches
{
	class IAT_Custom_Map_Navigation
	{
		requiredAddons[] = { "DZ_Gear_Navigation" };
	};
};

class CfgVehicles
{
	/*
	* Create our own map class that will help us later
	* distinguish between OUR maps and OTHER maps.
	* Inherit from ChernarusMap so we dont have to add any scripts
	* other than changing out the map to display when opened
	*/
	class ChernarusMap;
	class IAT_CustomMap_ColorBase : ChernarusMap
    {
        scope=0;
        displayName="Custom Map";
        descriptionShort="A custom map that can display any texture you want.";
		// these are the selections within the map.p3d that are exposed to us modders
		hiddenSelections[]={"texture_map_closed", "texture_map_opened", "texture_legend"};
		// setting some default textures to prove this works
        hiddenSelectionsTextures[]={"DZ\gear\camping\data\flag_alti_co.paa", "DZ\gear\camping\data\flag_bear_co.paa", "DZ\gear\camping\data\flag_dayz_co.paa"};
    };

	// making a concrete class that a player can hold in their hands
	class IAT_CustomMap_Example1 : IAT_CustomMap_ColorBase
    {
        scope=2;
        displayName="Example Map 1";
        descriptionShort="Map with custom contents";
    };
	class IAT_CustomMap_Example2 : IAT_CustomMap_ColorBase
    {
        scope=2;
        displayName="Example Map 2";
        descriptionShort="Map with custom contents";
        hiddenSelectionsTextures[]={"dz\gear\camping\Data\Flag_CDF_co.paa", "dz\gear\camping\Data\Flag_wolf_co.paa", "dz\gear\camping\Data\Flag_refuge_co.paa"};
    };
};