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
        simulation = "ItemRadio";
        oldpower = 0;
        repairableWithKits[] = { 7 };
        repairCosts[] = { 25 };
        hiddenSelections[] = { "metal", "wood" };
        hiddenSelectionsTextures[] = { "iat_prop_items\radio\data\iat_gramaphone_co.paa", "iat_prop_items\radio\data\iat_gramaphone_co.paa" };
        class EnergyManager
        {
            hasIcon = 1;
            autoSwitchOff = 1;
            energyUsagePerSecond = 0.02;
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
};