class CfgPatches
{
    class IAT_Prop_Items_Structures_Furniture
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts", "DZ_Structures_Furniture" };
    };
};
class CfgVehicles
{
    class HouseNoDestruct;

    class IAT_OccultTable_essesentiendum : HouseNoDestruct
    {
        scope = 1;
        displayName = "Occult Table";
        model = "iat_prop_items\structures\furniture\iat_occulttable.p3d";
    };
};