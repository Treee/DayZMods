class CfgPatches
{
	class IAT_Display_Case_Camping
	{
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
	};
};
class CfgVehicles
{
    class Inventory_Base;
	class Container_Base;
    // ====================================================== COLORBASE
    class IAT_DisplayCase_ColorBase : Container_Base
    {
        scope = 0;
        displayName = "Display Case";
        descriptionShort = "An area to showcase a special item.";
        model="iat_display_case\camping\iat_displaycase_coaster.p3d";
        physLayer = "item_large";
        weight = 10000;
        itemBehaviour=0;
        itemSize[] = { 10,15 };
        itemsCargoSize[] = { 12,12 };
        allowOwnedCargoManipulation = "true";
        hiddenSelections[] = {"zbytek", "glass"};
        hiddenSelectionsTextures[] ={"dz\gear\consumables\data\pile_of_planks_co.paa"};
        /*
        * Should the base of this display case be hidden when something is in the cargo?
        * Useful when you want a clean display of the object.
        */
        m_IAT_HideDisplayBaseWhenFull = "false";
        /*
        * Is this display case supposed to animate the displayed object? true/false
        * When false, this will ensure no frame/simulation is being added to the display
        */
        m_IAT_IsAnimated = "false";
        /*
        * Given a full cycle, how much distance does the displayed object travel in one direction.
        * The up/down movement is driven by a Math.Sin(dt * 2Pi * Frequency) curve to ensure the object
        * oscillates in mirrored movement. The amplitude increases/descreases the amount this object
        * swings from Pi to -Pi.
        */
        m_IAT_BobAmplitude = 0.0;
        /*
        * How large of a step should each movement be? Given the above Sin function, the frequency will influence
        * how often a full cycle will take to complete. Smaller numbers slows the up/down movement and
        * larger numbers speeds up the bob.
        */
        m_IAT_BobFrequency = 0.0;
        /*
        * How fast should the displayed object rotate per update? Smaller numbers will yield slower rotation
        * while larger numbers will result in faster rotation. Take note that since this is trigonometry
        * 360 degrees is the largest "effective" value you need. Anything higher will just wrap around (mathematically)
        * to the beginning of the circle. Negative numbers will reverse the default direction of the rotation
        */
        m_IAT_RotationSpeedDegrees = 0.0;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100000;
                };
            };
        };
       	class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet="pickUpPaper_SoundSet";
                    id=797;
                };
            };
        };
    };
	class IAT_DisplayCaseKit_ColorBase : Inventory_Base
	{
		scope=0; //0 means cannot be directly spawned
		displayName="Kit Box";
		descriptionShort="A wooden box used to transport small items. Find a suitable place to construct. Can be disassembled.";
		model="\DZ\gear\camping\wooden_case.p3d";
		itemsCargoSize[]={0,0};
		itemSize[]={7,5};
		carveNavmesh=1;
		canBeDigged=0;
		simulation="inventoryItem";
		physLayer="item_small";
		rotationFlags=2;
		heavyItem=1;
		weight=3000;
		itemBehaviour=2;
		hiddenSelections[]={"camoground"};
		hiddenSelectionsTextures[]={"\dz\gear\camping\data\wooden_case_co.paa"};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=400;
                    transferToAttachmentsCoef=0.06;
                    healthLevels[]={{1, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.7, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.5, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0, {"DZ\gear\camping\data\wooden_case_destruct.rvmat"}}};
                };
            };
            class GlobalArmor
            {
                class FragGrenade
                {
                    class Health
                    {
                        damage=8;
                    };
                    class Blood
                    {
                        damage=8;
                    };
                    class Shock
                    {
                        damage=8;
                    };
                };
            };
        };
		class AnimEvents
        {
            class SoundWeapon
            {
                class movement
                {
                    soundSet="seachest_movement_SoundSet";
                    id=1;
                };
                class pickUpItem_Light
                {
                    soundSet="pickUpSeaChest_SoundSet";
                    id=796;
                };
                class pickUpItem
                {
                    soundSet="pickUpSeaChest_SoundSet";
                    id=797;
                };
                class drop
                {
                    soundset="seachest_drop_SoundSet";
                    id=898;
                };
            };
        };
	};

    // ====================================================== CONCRETE CLASSES
	class IAT_DisplayCaseKit_Coaster : IAT_DisplayCaseKit_ColorBase
	{
		scope = 2;
		displayName="Display Case Kit - Coaster";
		descriptionShort="A small, low profile coaster for displaying an object.";
		projectionTypename = "IAT_DisplayCase_Coaster";
		color = "coaster";
	};
	class IAT_DisplayCase_Coaster: IAT_DisplayCase_ColorBase
	{
		scope = 2;
		displayName="Display Case - Coaster";
		descriptionShort="A small, low profile coaster for displaying an object.";
		color = "coaster";
        m_IAT_HideDisplayBaseWhenFull = "true";
	};

    class IAT_DisplayCaseKit_Glass : IAT_DisplayCaseKit_ColorBase
	{
		scope = 2;
		displayName="Display Case Kit - Glass";
		descriptionShort="A large, glass display for showcasing an object.";
		projectionTypename = "IAT_DisplayCase_Glass";
		color = "glass";
	};
	class IAT_DisplayCase_Glass: IAT_DisplayCase_ColorBase
	{
		scope = 2;
		displayName="Display Case - Glass";
		descriptionShort="A large, glass display for showcasing an object.";
        model="iat_display_case\camping\iat_displaycase_glass.p3d";
		color = "glass";
        hiddenSelections[] = {"zbytek", "glass"};
        hiddenSelectionsTextures[] ={"iat_display_case\camping\data\iat_displaycase_co.paa", "iat_display_case\camping\data\iat_displaycaseglass_ca.paa"};
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100000;
                    healthLevels[] =
                    {
                        {1.0,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.699,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.5,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.301,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.0,{"iat_display_case\camping\data\iat_displaycase.rvmat"}}
                    };
                };
            };
        };
	};

    class IAT_DisplayCaseKit_GlassAnimated : IAT_DisplayCaseKit_ColorBase
	{
		scope = 2;
		displayName="Display Case Kit - Glass (Animated)";
		descriptionShort="A large, glass display for showcasing an object.";
		projectionTypename = "IAT_DisplayCase_GlassAnimated";
		color = "glassanimated";
	};
	class IAT_DisplayCase_GlassAnimated: IAT_DisplayCase_ColorBase
	{
		scope = 2;
		displayName="Display Case - Glass";
		descriptionShort="A large, glass display for showcasing an object.";
        model="iat_display_case\camping\iat_displaycase_glass.p3d";
		color = "glassanimated";
        hiddenSelections[] = {"zbytek", "glass"};
        hiddenSelectionsTextures[] ={"iat_display_case\camping\data\iat_displaycase_co.paa", "iat_display_case\camping\data\iat_displaycaseglass_ca.paa"};
        m_IAT_HideDisplayBaseWhenFull = "false";
        m_IAT_IsAnimated = "true";
        m_IAT_BobAmplitude = 2.0;
        m_IAT_BobFrequency = 0.15;
        m_IAT_RotationSpeedDegrees = 10.0;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100000;
                    healthLevels[] =
                    {
                        {1.0,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.699,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.5,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.301,{"iat_display_case\camping\data\iat_displaycase.rvmat"}},
                        {0.0,{"iat_display_case\camping\data\iat_displaycase.rvmat"}}
                    };
                };
            };
        };
	};
};