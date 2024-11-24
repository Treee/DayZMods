class CfgPatches
{
    class SRP_Core_Characters_Vests
    {
        units[] = {	};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Characters_Vests"
        };
    };
};
class CfgVehicles
{
    class Clothing;

    // ----------------------  BASE GAME OVERRIDES
    class PlateCarrierVest : Clothing
    {
        itemSize[] = { 5,4 };
        heatIsolation = 0.2;
        repairableWithKits[] = { 5,3,7 };
        repairCosts[] = { 30,25,25 };
        rootClassName = "PlateCarrierVest";
        colorVariants[] =
        {
          "Trader",
          "Black",
          "Green",
          "Camo",
          "White",
          "Pseudo",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR2",
          "USNAOR1",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
          "Lavender",
          "Petal",
          "Stone",
          "Storm",
          "Sunny",
        };
    };
    class PlateCarrierHolster : Clothing
    {
        itemSize[] = { 2,2 };
        repairableWithKits[] = { 5,3,7 };
        repairCosts[] = { 30,25,25 };
        heatIsolation = 0.1;
        rootClassName = "PlateCarrierHolster";
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
    class SmershVest : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "SmershVest";
        colorVariants[] =
        {
          "White",
          "Black",
          "Green",
          "Tan",
          "Red",
          "Purple",
          "Blue",
          "Pink",
          "Olive",
          "Storm",
        };
    };
    class PressVest_ColorBase : Clothing
    {
        repairableWithKits[] = { 5,3,7 };
        repairCosts[] = { 30,25,25 };
        itemsCargoSize[] = { 9,4 };
        rootClassName = "PressVest";
        colorVariants[] =
        {
          "Black",
          "Blue",
          "LightBlue",
          "ATFBlue",
          "CIABlue",
          "FBIBlue",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
        };
    };
    class UKAssVest_ColorBase : Clothing
    {
        itemsCargoSize[] = { 6,5 };
        rootClassName = "UKAssVest";
        colorVariants[] =
        {
          "Black",
          "Camo",
          "Khaki",
          "Olive",
          "White",
        };
    };
    class PoliceVest : Clothing
    {
        rootClassName = "PoliceVest";
        colorVariants[] =
        {
          "Sheriff",
          "ATF",
          "CIA",
          "FBI",
          "NoLetters",
        };
    };
    class ChestHolster : Clothing
    {
        rootClassName = "ChestHolster";
        colorVariants[] =
        {
          "Black",
          "White",
        };
    };
    class HighCapacityVest_ColorBase : Clothing
    {
        itemsCargoSize[] = { 8,5 };
        repairableWithKits[] = { 5,3,7 };
        repairCosts[] = { 30,25,25 };
        rootClassName = "HighCapacityVest";
        colorVariants[] =
        {
          "Black",
          "Olive",
          "Rain",
          "ATFBlack",
          "ATFOlive",
          "CIABlack",
          "CIAOlive",
          "FBIBlack",
          "FBIOlive",
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
    class LeatherStorageVest_ColorBase : Clothing
    {
        itemsCargoSize[] = { 7,5 };
        rootClassName = "LeatherStorageVest";
        colorVariants[] =
        {
          "Natural",
          "Beige",
          "Brown",
          "Black",
          "Choco",
          "Lime",
          "Orange",
          "Pink",
          "Purple",
          "Storm",
          "Yellow",
        };
    };
    class HuntingVest : Clothing
    {
        itemsCargoSize[] = { 7,5 };
        rootClassName = "HuntingVest";
        colorVariants[] =
        {
          "Leather",
        };
    };
};