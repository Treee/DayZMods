class CfgPatches
{
    class IAT_Prop_Items_Structures_Industrial
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Structures_Industrial" };
    };
};
class CfgVehicles
{
    class HouseNoDestruct;

    class IAT_PowerpoleAmp_wadethemechanic : HouseNoDestruct
    {
        scope = 1;
        displayName = "$STR_CfgVehicles_Land_Power_Pole_Conc1_Amp0";
        model = "\dz\structures\industrial\power\power_pole_conc1_amp.p3d";
    };
};