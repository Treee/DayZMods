class CfgPatches
{
    class SRP_Core_Gear_Containers
    {
        units[] = {	};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Gear_Containers",
        };
    };
};
class CfgVehicles
{
    class Container_Base;

    // ----------------------  BASE GAME OVERRIDES
    class PlateCarrierPouches : Container_Base
    {
        itemSize[] = { 6,4 };
        itemsCargoSize[] = { 6,4 };
        repairCosts[] = { 30,25,25 };
        rootClassName = "PlateCarrierPouches";
        colorVariants[] =
        {
          "White",
          "Pseudo",
          "Tan",
          "Green",
          "Camo",
          "Black",
          "Lavender",
          "Petal",
          "Stone",
          "Storm",
          "Sunny",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR2",
          "USNAOR1",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
        };
    };

};