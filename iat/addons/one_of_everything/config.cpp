class CfgPatches
{
    class IAT_OneOfEverything
    {
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
    };
};
class CfgMods
{
    class IAT_OneOfEverything
    {
        type = "mod";
        author = "ItsATreee";
        name = "ItsATreee Spawn One Of Everything";
        dependencies[] = { "Game", "World", "Mission" };
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "iat/one_of_everything/scripts/3_game" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "iat/one_of_everything/scripts/4_world" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "iat/one_of_everything/scripts/5_mission" };
            };
        };
    };
};