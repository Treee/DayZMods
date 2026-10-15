class CfgPatches
{
    class IAT_Crafting_Plus_Consumables
    {
        requiredAddons[] = { "DZ_Data", "DZ_Gear_Consumables" };
    };
};
class CfgVehicles
{
    class Chemlight_ColorBase;

    class Chemlight_White : Chemlight_ColorBase
    {
        color = "white";
    };
    class Chemlight_Red : Chemlight_ColorBase
    {
        color = "red";
    };
    class Chemlight_Green : Chemlight_ColorBase
    {
        color = "green";
    };
    class Chemlight_Blue : Chemlight_ColorBase
    {
        color = "blue";
    };
    class Chemlight_Yellow : Chemlight_ColorBase
    {
        color = "yellow";
    };
};