class CfgPatches
{
    class IAT_Prop_Items_Radio
    {
        requiredAddons[] = { "DZ_Radio" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class IAT_Gramaphone_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Gramaphone";
        descriptionShort = "An old time gramaphone that spins to turn a table and needle that plays the record. Hand cranked so no battery required.";
        model = "iat_prop_items\radio\iat_gramaphone.p3d";
        animClass = "Knife";
        weight = 6400;
        itemSize[] = { 3, 3 };
        itemBehaviour = 0;
        fragility = 0.01;
        absorbency = 0.5;
        oldpower = 0;
        repairableWithKits[] = { 7 };
        repairCosts[] = { 25 };
        attachments[] = { "BatteryD", "IAT_VinylRecord" };
        hiddenSelections[] = { "metal", "wood" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\iat_gramaphone_co.paa", "iat_prop_items\radio\data\iat_gramaphone_co.paa" };
        class EnergyManager
        {
            hasIcon = 1;
            autoSwitchOff = 1;
            energyUsagePerSecond = 0.01;
            attachmentAction = 1;
            wetnessExposure = 0.1;
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 150;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\radio\data\iat_gramaphone_metal.rvmat","iat_prop_items\radio\data\iat_gramaphone_wood.rvmat"}},
                        {0.7, {"iat_prop_items\radio\data\iat_gramaphone_metal.rvmat","iat_prop_items\radio\data\iat_gramaphone_wood.rvmat"}},
                        {0.5, {"iat_prop_items\radio\data\iat_gramaphone_metal_damage.rvmat","iat_prop_items\radio\data\iat_gramaphone_wood_damage.rvmat"}},
                        {0.3, {"iat_prop_items\radio\data\iat_gramaphone_metal_damage.rvmat","iat_prop_items\radio\data\iat_gramaphone_wood_damage.rvmat"}},
                        {0, {"iat_prop_items\radio\data\iat_gramaphone_metal_destruct.rvmat","iat_prop_items\radio\data\iat_gramaphone_wood_destruct.rvmat"}} };
                };
            };
        };
        class AnimationSources
        {
            class vinyl
            {
                source = "user";
                initPhase = 1;   // start hidden until attachment is present
                animPeriod = 0.01;
            };
            class vinyl_rotate
            {
                source = "user";
                initPhase = 1;   // start stationary until turned on
                animPeriod = 1;
            };
        };
        soundImpactType = "plastic";
    };

    class IAT_Gramaphone_Basic : IAT_Gramaphone_Colorbase
    {
        scope = 2;
    };
    class IAT_Gramaphone_Essesentiendum : IAT_Gramaphone_Colorbase
    {
        scope = 2;
    };

    // ===================================== BOOSTER PACK
    class IAT_VinylBoosterPack_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Vinyl Booster Pack";
        descriptionShort = "A random vinyl. Roll the dice!";
        model = "iat_prop_items\radio\iat_vinylcover.p3d";
        rotationFlags = 17;
        quantityBar = 1;
        itemSize[] = { 2, 2 };
        weight = 30;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\vinyls\iat_vinylcardboard_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 5;
                    healthLevels[] = { {1, {"iat_prop_items\radio\data\vinyls\iat_vinylcover.rvmat"}}, {0.7, {"iat_prop_items\radio\data\vinyls\iat_vinylcover.rvmat"}}, {0.5, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0.3, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_damage.rvmat"}}, {0, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_destruct.rvmat"}} };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup
                {
                    soundSet = "seedpack_pickup_SoundSet";
                    id = 797;
                };
            };
        };
    };
    class IAT_VinylBoosterPack_PlayableVinylCover : IAT_VinylBoosterPack_ColorBase
    {
        scope = 2;
        displayName = "Playable Vinyl Covers";
        color = "playablevinylcover";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\vinyls\iat_vinylcardboard_co.paa" };
    };
    //==================================== PLAYABLE VINYLS
    class IAT_PlayableVinylCover_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Playable Vinyl Cover";
        descriptionShort = "A cardboard cover for a vinyl record that can be played on a record player.";
        model = "iat_prop_items\radio\iat_vinylcover.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        soundImpactType = "textile";
        inventorySlot[] = { "IAT_VinylRecord" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\vinyls\iat_vinylcover_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\radio\data\vinyls\iat_vinylcover.rvmat"}},
                        {0.7, {"iat_prop_items\radio\data\vinyls\iat_vinylcover.rvmat"}},
                        {0.5, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_damage.rvmat"}},
                        {0.3, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_damage.rvmat"}},
                        {0, {"iat_prop_items\radio\data\vinyls\iat_vinylcover_destruct.rvmat"}}
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
    };
    class IAT_PlayableVinylRecord_ColorBase : Inventory_Base
    {
        scope = 0;
        displayName = "Playable Vinyl Record";
        descriptionShort = "A vinyl record that can be played on a record player.";
        model = "iat_prop_items\radio\iat_vinyl_normal.p3d";
        weight = 2;
        absorbency = 1;
        rotationFlags = 16;
        itemBehaviour = 1;
        itemSize[] = { 1, 1 };
        itemsCargoSize[] = { 0,0 };
        inventorySlot[] = { };
        soundImpactType = "textile";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\vinyls\iat_vinylcenter_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 50;
                    healthLevels[] =
                    {
                        {1, {"iat_prop_items\radio\data\vinyls\iat_vinyl.rvmat"}},
                        {0.7, {"iat_prop_items\radio\data\vinyls\iat_vinyl.rvmat"}},
                        {0.5, {"iat_prop_items\radio\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0.3, {"iat_prop_items\radio\data\vinyls\iat_vinyl_damage.rvmat"}},
                        {0, {"iat_prop_items\radio\data\vinyls\iat_vinyl_destruct.rvmat"}}
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "pickUpPaper_SoundSet";
                    id = 797;
                };
            };
        };
    };

    // default for this record. meant to be the retextured version for players?
    class IAT_PlayableVinylRecord_Default : IAT_PlayableVinylRecord_ColorBase
    {
        scope = 2;
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_ABetterDay";
        };
    };

    class IAT_PlayableVinylCover_ABetterDay : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "A Better Day";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_ABetterDay";
        };
    };
    class IAT_PlayableVinylCover_ChantsOfTheWild : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Chants of the Wild";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_ChantsOfTheWild";
        };
    };
    class IAT_PlayableVinylCover_ForgedInTheFire : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Forged in the Fire";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_ForgedInTheFire";
        };
    };
    class IAT_PlayableVinylCover_HerosFight : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Heros Fight";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_HerosFight";
        };
    };
    class IAT_PlayableVinylCover_HerosRest : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "A Better Day";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_HerosRest";
        };
    };
    class IAT_PlayableVinylCover_IntoTheMaw : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Into The Maw";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_IntoTheMaw";
        };
    };
    class IAT_PlayableVinylCover_RustAndReverie : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Rust And Reverie";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_RustAndReverie";
        };
    };
    class IAT_PlayableVinylCover_SlowRoll : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Slow Roll";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_SlowRoll";
        };
    };
    class IAT_PlayableVinylCover_Subterfuge : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Subterfuge";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_Subterfuge";
        };
    };
    class IAT_PlayableVinylCover_VelvetNights : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Veltvet Nights";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_VelvetNights";
        };
    };
    class IAT_PlayableVinylCover_VictoryDance : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Victory Dance";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_VictoryDance";
        };
    };
    class IAT_PlayableVinylCover_VortexOfTheDamned : IAT_PlayableVinylCover_ColorBase
    {
        scope = 2;
        displayName = "Vortex of the Damned";
        class CfgCassette
        {
            soundSet = "IAT_PI_Vinyl_SoundSet_VortexOfTheDamned";
        };
    };

};

class CfgSlots
{
    class Slot_IAT_VinylRecord
    {
        name = "IAT_VinylRecord";
        displayName = "Playable Vinyl Record";
        ghostIcon = "set:dayz_inventory image:missing";
        stackMax = 1;
    };
};