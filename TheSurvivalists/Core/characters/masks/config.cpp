class CfgPatches
{
    class SRP_Core_Characters_Masks
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Characters",
            "DZ_Characters_Masks"
        };
    };
};
class CfgVehicles
{
    // class Mask_Base;
    class Clothing;
    //------------------------------------- BASE GAME OVERRIDE
    class GasMask : Clothing
    {
        soundVoiceType = "none";
        soundVoicePriority = 3;
        itemSize[] = { 2,2 };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class BalaclavaMask_ColorBase : Clothing
    {
        itemSize[] = { 1,2 };
        rootClassName = "BalaclavaMask";
        colorVariants[] =
        {
          "Black",
          "BlackSkull",
          "Beige",
          "Blue",
          "Green",
          "Pink",
          "White",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
        };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class Balaclava3Holes_ColorBase : Clothing
    {
        itemSize[] = { 1,2 };
        rootClassName = "Balaclava3Holes";
        colorVariants[] =
        {
          "Black",
          "BlackSkull",
          "Beige",
          "Blue",
          "Green",
          "Pink",
          "White",
          "MTP",
          "ATAC",
          "ATACSFG",
          "USNAOR1",
          "USNAOR2",
          "SURPAT",
          "MARPATWinter",
          "EMP6",
        };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class GP5GasMask : Clothing
    {
        soundVoiceType = "none";
        soundVoicePriority = 3;
        itemSize[] = { 2,2 };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class SurgicalMask : Clothing
    {
        rootClassName = "SurgicalMask";
        colorVariants[] =
        {
          "Black"
        };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class HockeyMask : Clothing
    {
        rootClassName = "HockeyMask";
        colorVariants[] =
        {
          "Steel"
        };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class MimeMask_Male : Clothing
    {
        rootClassName = "MimeMask_Male";
        colorVariants[] =
        {
        };
        inventorySlot[] +=
        {
            "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class MimeMask_Female : MimeMask_Male
    {
        rootClassName = "MimeMask_Female";
        colorVariants[] =
        {
        };
        inventorySlot[] +=
        {
            "Mask",
                "SRP_Mask1",
                "SRP_Mask2",
                "SRP_Mask3",
                "SRP_Mask4",
                "SRP_Mask5",
                "SRP_Mask6",
                "SRP_Mask7",
                "SRP_Mask8",
                "SRP_Mask9",
                "SRP_Mask10",
        };
    };
    class FaceCover_Improvised : Clothing
    {
        rootClassName = "FaceCover_Improvised";
        colorVariants[] =
        {
          "Green",
          "Black",
          "Orange",
          "Blue",
          "Red",
        };
    };
    class NioshFaceMask : Clothing
    {
        rootClassName = "NioshFaceMask";
        colorVariants[] =
        {
          "WaldoRescue",
        };
    };
};