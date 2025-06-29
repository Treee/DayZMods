class CfgPatches
{
    class IAT_Prop_Items_Medical
    {
        requiredAddons[] = { "DZ_Gear_Medical" };
    };
};
class CfgVehicles
{
    class Clothing;
    class Inventory_Base;

    class IAT_LegCast_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "A plaster leg cast";
        descriptionShort = "A cast made from makeshift materials to hold a fracture in place.";
        model = "iat_prop_items\medical\iat_legcast_g.p3d";
        debug_ItemCategory = 7;
        rotationFlags = 17;
        itemSize[] = { 2,4 };
        weight = 540;
        absorbency = 0.3;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 70;
                    healthLevels[] = { {1,{"iat_prop_items\medical\data\iat_legcast.rvmat"}},{0.7,{"iat_prop_items\medical\data\iat_legcast.rvmat"}},{0.5,{"iat_prop_items\medical\data\iat_legcast_damage.rvmat"}},{0.3,{"iat_prop_items\medical\data\iat_legcast_damage.rvmat"}},{0.1,{"iat_prop_items\medical\data\iat_legcast_destruct.rvmat"}} };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeLightBlunt";
                range = 1.4;
            };
            class Heavy
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 1.4;
            };
            class Sprint
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 3.3;
            };
        };
    };
    class IAT_LegCastApplied_Colorbase : Clothing
    {
        scope = 0;
        displayName = "A plaster leg cast";
        descriptionShort = "A cast made from makeshift materials to hold a fracture in place.";
        model = "iat_prop_items\medical\iat_legcast_g.p3d";
        inventorySlot[] = { "Splint_Right" };
        simulation = "clothing";
        rotationFlags = 17;
        itemSize[] = { 2,4 };
        weight = 540;
        absorbency = 0.3;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
        class ClothingTypes
        {
            male = "iat_prop_items\medical\iat_legcast_m.p3d";
            female = "iat_prop_items\medical\iat_legcast_m.p3d";
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 70;
                    healthLevels[] = { {1,{"iat_prop_items\medical\data\iat_legcast.rvmat"}},{0.7,{"iat_prop_items\medical\data\iat_legcast.rvmat"}},{0.5,{"iat_prop_items\medical\data\iat_legcast_damage.rvmat"}},{0.3,{"iat_prop_items\medical\data\iat_legcast_damage.rvmat"}},{0.1,{"iat_prop_items\medical\data\iat_legcast_destruct.rvmat"}} };
                };
            };
        };
        class AnimationSources
        {
            class cover
            {
                source = "user";
                animPeriod = 0.5;
                initPhase = 1;
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeLightBlunt";
                range = 1.4;
            };
            class Heavy
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 1.4;
            };
            class Sprint
            {
                ammo = "MeleeLightBlunt_Heavy";
                range = 3.3;
            };
        };
    };


    class IAT_LegCast_Basic : IAT_LegCast_Colorbase
    {
        scope = 2;
        color = "Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCastApplied_Basic : IAT_LegCastApplied_Colorbase
    {
        scope = 2;
        color = "Basic";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCast_Permanent : IAT_LegCast_Colorbase
    {
        scope = 2;
        color = "Permanent";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCastApplied_Permanent : IAT_LegCastApplied_Colorbase
    {
        scope = 2;
        color = "Permanent";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCast_DotsNotsStripes : IAT_LegCast_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCastApplied_DotsNotsStripes : IAT_LegCastApplied_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };

    class IAT_LegCast_FastHealing : IAT_LegCast_Colorbase
    {
        scope = 2;
        color = "FastHealing";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCastApplied_FastHealing : IAT_LegCastApplied_Colorbase
    {
        scope = 2;
        color = "FastHealing";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };

    class IAT_LegCast_Infected : IAT_LegCast_Colorbase
    {
        scope = 2;
        color = "Infected";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
    class IAT_LegCastApplied_Infected : IAT_LegCastApplied_Colorbase
    {
        scope = 2;
        color = "Infected";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_prop_items\medical\data\iat_legcast_co.paa" };
    };
};