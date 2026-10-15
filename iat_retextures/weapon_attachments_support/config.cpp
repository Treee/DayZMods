class CfgPatches
{
    class IAT_Retextures_Weapon_Attachments_Support
    {
        requiredAddons[] = { "DZ_Weapons_Supports" };
    };
};
class CfgVehicles
{
    class GhillieAtt_ColorBase;

    //==================================================== VANILLA RETEXTURES
    class GhillieAtt_White : GhillieAtt_ColorBase
    {
        scope = 2;
        color = "White";
        displayName = "Ghillie Wrap - Winter";
        descriptionShort = "A wrap for your firearm.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_winter_co.paa"
        };
    };
    class GhillieAtt_Black : GhillieAtt_ColorBase
    {
        scope = 2;
        color = "Black";
        displayName = "Ghillie Wrap - Black";
        descriptionShort = "A wrap for your firearm.";
        hiddenSelectionsTextures[] =
        {
            "iat_retextures\backpacks\data\ghillie_black_co.paa"
        };
    };
};
