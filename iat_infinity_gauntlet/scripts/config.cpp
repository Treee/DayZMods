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
        dependencies[] = { "Game", "World","Mission" };
        class defs
        {
            class gameScriptModule
            {
                files[] = { "iat_infinity_gauntlet/scripts/3_game" };
            };
            class worldScriptModule
            {
                files[] = { "iat_infinity_gauntlet/scripts/4_world" };
            };
            class missionScriptModule
            {
                files[] = { "iat_infinity_gauntlet/scripts/5_mission" };
            };
        };
    };
};