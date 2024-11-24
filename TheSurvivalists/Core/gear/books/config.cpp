class CfgPatches
{
    class SRP_Core_Gear_Books
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "Dressupbox_Items",
        };
    };
};
class CfgVehicles
{
    class Inventory_Base;
    class DUB_Newspaper_Base : Inventory_Base
    {
        inventorySlot[] += {
            "SRP_Book1",
                "SRP_Book2",
                "SRP_Book3",
                "SRP_Book4",
                "SRP_Book5",
                "SRP_Book6",
                "SRP_Book7",
                "SRP_Book8",
                "SRP_Book9",
                "SRP_Book10",
                "SRP_Book11",
                "SRP_Book12",
                "SRP_Book13",
                "SRP_Book14",
                "SRP_Book15",
                "SRP_Book16",
                "SRP_Book17",
                "SRP_Book18",
                "SRP_Book19",
                "SRP_Book20",
        };
    };
};