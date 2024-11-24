class CfgPatches
{
    class SRP_Core_Weapons_Smgs
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "Dressupbox_Weapons",
            "Survivalists_RPWeapons_Smgs_ttp90"
        };
    };
};
class CfgWeapons
{
    class CZ61_Base;
    class CZ61 : CZ61_Base
    {
        inventorySlot[] +=
        {
            "Shoulder",
                "Melee",
                "pistol", "LeftHand1", "pistol2",
                "SRP_Pistol1",
                "SRP_Pistol2",
                "SRP_Pistol3",
                "SRP_Pistol4",
                "SRP_Rifle1",
                "SRP_Rifle2",
                "SRP_Rifle3",
                "SRP_Rifle4",
                "SRP_Rifle5",
                "SRP_Rifle6",
                "SRP_Rifle7",
                "SRP_Rifle8",
                "SRP_Rifle9",
                "SRP_Rifle10",
                "Shoulder1",
                "Shoulder2",
                "Shoulder3",
                "Shoulder4",
                "Shoulder5",
                "Shoulder6",
                "Shoulder7",
                "Shoulder8",
                "Shoulder9",
                "Shoulder10",
                "Shoulder11",
                "Shoulder12",
                "Shoulder13",
                "Shoulder14",
                "Shoulder15",
                "Shoulder16",
                "Shoulder17",
                "Shoulder18",
                "Shoulder19",
                "Shoulder20",
        };
    };
    class ttp90 : CZ61
    {
        inventorySlot[] +=
        {
            "Shoulder",
                "Melee",
                "SRP_Pistol1",
                "SRP_Pistol2",
                "SRP_Pistol3",
                "SRP_Pistol4",
                "SRP_Rifle1",
                "SRP_Rifle2",
                "SRP_Rifle3",
                "SRP_Rifle4",
                "SRP_Rifle5",
                "SRP_Rifle6",
                "SRP_Rifle7",
                "SRP_Rifle8",
                "SRP_Rifle9",
                "SRP_Rifle10",
                "Shoulder1",
                "Shoulder2",
                "Shoulder3",
                "Shoulder4",
                "Shoulder5",
                "Shoulder6",
                "Shoulder7",
                "Shoulder8",
                "Shoulder9",
                "Shoulder10",
                "Shoulder11",
                "Shoulder12",
                "Shoulder13",
                "Shoulder14",
                "Shoulder15",
                "Shoulder16",
                "Shoulder17",
                "Shoulder18",
                "Shoulder19",
                "Shoulder20",
        };
    };
};