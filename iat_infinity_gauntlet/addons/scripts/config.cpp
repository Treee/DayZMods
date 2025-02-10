class CfgPatches
{
    class IAT_InfinityGauntlet_Scripts
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgMods
{
    class IAT_InfinityGauntlet
    {
        type = "mod";
        author = "ItsATreee";
        name = "ItsATreee Infinity Gauntlet";
        dependencies[] = { "World","Mission" };
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = { "iat_infinity_gauntlet\scripts\4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "iat_infinity_gauntlet\scripts\5_mission" };
            };
        };
    };
};