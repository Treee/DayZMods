class CfgPatches
{
    class IAT_LiteraryDevices_Tools
    {
        requiredAddons[] = { "DZ_Gear_Tools" };
    };
};
class CfgVehicles
{
    class Inventory_Base;

    class Pen_ColorBase : Inventory_Base
    {
        inventorySlot[] += { "IAT_Pen" };
    };
};