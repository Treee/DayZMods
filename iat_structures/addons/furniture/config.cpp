class CfgPatches
{
    class IAT_Structures_Furniture
    {
        requiredAddons[] = { "DZ_Structures", "DZ_Structures_Furniture" };
    };
};

class CfgVehicles
{
    class HouseNoDestruct;

    class StaticObj_Furniture_UniqueItem_GypsyWagon_Default : HouseNoDestruct
    {
        scope = 1;
        displayName = "Gypsy Wagon";
        descriptionShort = "A large wagon with room at the front to sit.";
        model = "iat_structures\furniture\iat_gypsywagon.p3d";
        carveNavmesh = 1;
        weight = 500;
        itemSize[] = { 10,10 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        minPlacingDist = 5;
        slopeTolerance = 0.2;
        alignHologramToTerain = 1;
        hiddenSelections[] = { "door", "door1", "planks", "roof", "seat", "wheel", "windows" };
        hiddenSelectionsTextures[] =
        {
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_planks_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_roof_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_wheel_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_windows_co.paa"
        };
        class Doors
        {
            class Door1
            {
                displayName = "door 1";
                component = "door1";
                soundPos = "door1_action";
                animPeriod = 1;
                initPhase = 0;
                initOpened = 0.5;
                soundOpen = "doorWoodSmallOpen";
                soundClose = "doorWoodSmallClose";
                soundLocked = "doorWoodSmallRattle";
                soundOpenABit = "doorWoodSmallOpenABit";
            };
            class Door2
            {
                displayName = "door 2";
                component = "door2";
                soundPos = "door2_action";
                animPeriod = 1;
                initPhase = 0;
                initOpened = 0.5;
                soundOpen = "doorWoodSmallOpen";
                soundClose = "doorWoodSmallClose";
                soundLocked = "doorWoodSmallRattle";
                soundOpenABit = "doorWoodSmallOpenABit";
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health { damage = 0; };
                    class Blood { damage = 0; };
                    class Shock { damage = 0; };
                };
                class Melee
                {
                    class Health { damage = 0; };
                    class Blood { damage = 0; };
                    class Shock { damage = 0; };
                };
            };
            class DamageZones
            {
                class Door1
                {
                    class Health
                    {
                        hitpoints = 1000;
                        transferToGlobalCoef = 0;
                    };
                    componentNames[] = { "door1" };
                    fatalInjuryCoef = -1;
                    class ArmorType
                    {
                        class Projectile
                        {
                            class Health { damage = 2; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                        class Melee
                        {
                            class Health { damage = 2.5; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                    };
                };
                class Door2
                {
                    class Health
                    {
                        hitpoints = 1000;
                        transferToGlobalCoef = 0;
                    };
                    componentNames[] = { "door2" };
                    fatalInjuryCoef = -1;
                    class ArmorType
                    {
                        class Projectile
                        {
                            class Health { damage = 2; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                        class Melee
                        {
                            class Health { damage = 2.5; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                    };
                };
            };
        };
    };
    class StaticObj_Furniture_UniqueItem_GypsyWagon_essesentiendum : HouseNoDestruct
    {
        scope = 1;
        displayName = "Gypsy Wagon";
        descriptionShort = "A large wagon with room at the front to sit.";
        model = "iat_structures\furniture\iat_gypsywagon.p3d";
        carveNavmesh = 1;
        weight = 500;
        itemSize[] = { 10,10 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        minPlacingDist = 5;
        slopeTolerance = 0.2;
        alignHologramToTerain = 1;
        hiddenSelections[] = { "door", "door1", "planks", "roof", "seat", "wheel", "windows" };
        hiddenSelectionsTextures[] =
        {
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_planks_gypsy_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_roof_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_seat_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_wheel_co.paa",
            "iat_structures\furniture\data\iat_gypsywagon_windows_co.paa"
        };
        class Doors
        {
            class Door1
            {
                displayName = "door 1";
                component = "door1";
                soundPos = "door1_action";
                animPeriod = 1;
                initPhase = 0;
                initOpened = 0.5;
                soundOpen = "doorWoodSmallOpen";
                soundClose = "doorWoodSmallClose";
                soundLocked = "doorWoodSmallRattle";
                soundOpenABit = "doorWoodSmallOpenABit";
            };
            class Door2
            {
                displayName = "door 2";
                component = "door2";
                soundPos = "door2_action";
                animPeriod = 1;
                initPhase = 0;
                initOpened = 0.5;
                soundOpen = "doorWoodSmallOpen";
                soundClose = "doorWoodSmallClose";
                soundLocked = "doorWoodSmallRattle";
                soundOpenABit = "doorWoodSmallOpenABit";
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 1000;
                };
            };
            class GlobalArmor
            {
                class Projectile
                {
                    class Health { damage = 0; };
                    class Blood { damage = 0; };
                    class Shock { damage = 0; };
                };
                class Melee
                {
                    class Health { damage = 0; };
                    class Blood { damage = 0; };
                    class Shock { damage = 0; };
                };
            };
            class DamageZones
            {
                class Door1
                {
                    class Health
                    {
                        hitpoints = 1000;
                        transferToGlobalCoef = 0;
                    };
                    componentNames[] = { "door1" };
                    fatalInjuryCoef = -1;
                    class ArmorType
                    {
                        class Projectile
                        {
                            class Health { damage = 2; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                        class Melee
                        {
                            class Health { damage = 2.5; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                    };
                };
                class Door2
                {
                    class Health
                    {
                        hitpoints = 1000;
                        transferToGlobalCoef = 0;
                    };
                    componentNames[] = { "door2" };
                    fatalInjuryCoef = -1;
                    class ArmorType
                    {
                        class Projectile
                        {
                            class Health { damage = 2; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                        class Melee
                        {
                            class Health { damage = 2.5; };
                            class Blood { damage = 0; };
                            class Shock { damage = 0; };
                        };
                    };
                };
            };
        };
    };

    class StaticObj_Furniture_UniqueItem_Portal_Steampunk_Default : HouseNoDestruct
    {
        scope = 1;
        displayName = "Steampunk Portal";
        descriptionShort = "A large device that looks like it might blow up or teleport.";
        model = "iat_structures\furniture\iat_portal_steampunk.p3d";
        carveNavmesh = 1;
        weight = 500;
        itemSize[] = { 10,10 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        minPlacingDist = 5;
        slopeTolerance = 0.2;
        alignHologramToTerain = 1;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_structures\furniture\data\iat_portal_steampunk_co.paa" };
    };
    class StaticObj_Furniture_UniqueItem_Portal_Steampunk_chunkyhedgehog : HouseNoDestruct
    {
        scope = 1;
        displayName = "Steampunk Portal";
        descriptionShort = "A large device that looks like it might blow up or teleport.";
        model = "iat_structures\furniture\iat_portal_steampunk.p3d";
        carveNavmesh = 1;
        weight = 500;
        itemSize[] = { 10,10 };
        itemsCargoSize[] = { 0,0 };
        physLayer = "item_large";
        minPlacingDist = 5;
        slopeTolerance = 0.2;
        alignHologramToTerain = 1;
        useEntityHierarchy = "true";
        attachments[] = { "GlowPlug", "LargeBattery" };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_structures\furniture\data\iat_portal_steampunk_chunkyhedgehog_co.paa" };
        class EnergyManager
        {
            hasIcon = 1;
            autoSwitchOff = 1;
            energyUsagePerSecond = 2;
            updateInterval = 1;
            attachmentAction = 1;
        };
        class AnimationSources
        {
            class clock_rotate
            {
                source = "user";
                animPeriod = 2;
                initPhase = 0;
            };
            class platform_rotate
            {
                source = "user";
                animPeriod = 2;
                initPhase = 0;
            };
        };
    };

    class StaticObj_Furniture_TownBell_Default : HouseNoDestruct
    {
        scope = 1;
        displayName = "Town Bell";
        model = "iat_structures\furniture\iat_townbell.p3d";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_structures\furniture\data\iat_townbell_co.paa" };
    };
};
