class CfgPatches
{
    class IAT_LiteraryDevices_Tablets
    {
        requiredAddons[] = { "DZ_Gear_Books" };
    };
};
class CfgVehicles
{
    class ItemBook;

    class IAT_LiteraryDevices_HandHeldTablet_Colorbase : ItemBook
    {
        scope = 0;
        model = "iat_literary_devices\tablets\iat_handheldtablet.p3d";
        displayName = "Tablet";
        descriptionShort = "An electronic tablet.";
        itemSize[] = { 2,2 };
        rotationFlags = 8;
        booksInArchive[] = {};
        hiddenSelections[] = { "zbytek", "screen" };
        hiddenSelectionsTextures[] =
        {
            "iat_literary_devices\tablets\data\iat_tablet_co.paa",
            "iat_literary_devices\tablets\data\iat_tablet_console_co.paa",
        };
        hiddenSelectionsMaterials[] =
        {
            "iat_literary_devices\tablets\data\iat_tablet.rvmat",
            "iat_literary_devices\tablets\data\iat_tabletglass.rvmat",
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                    healthLevels[] =
                    {
                        {1,{"iat_literary_devices\tablets\data\iat_tablet.rvmat","iat_literary_devices\tablets\data\iat_tabletglass.rvmat"}},
                        {0.69999999,{"iat_literary_devices\tablets\data\iat_tablet.rvmat","iat_literary_devices\tablets\data\iat_tabletglass.rvmat"}},
                        {0.5,{"iat_literary_devices\tablets\data\iat_tablet_damage.rvmat","iat_literary_devices\tablets\data\iat_tabletglass_damage.rvmat"}},
                        {0.30000001,{"iat_literary_devices\tablets\data\iat_tablet_damage.rvmat","iat_literary_devices\tablets\data\iat_tabletglass_damage.rvmat"}},
                        {0,{"iat_literary_devices\tablets\data\iat_tablet_destruct.rvmat","iat_literary_devices\tablets\data\iat_tabletglass_destruct.rvmat"}},
                    };
                };
            };
        };
    };

    // ============================================= Tablets
    class IAT_LiteraryDevices_HandHeldTablet_Archive1 : IAT_LiteraryDevices_HandHeldTablet_Colorbase
    {
        scope = 2;
        displayName = "Tablet - Archive 1";
        booksInArchive[] =
        {
            "IAT_LiteraryDevices_Book_CodeBreakers",
            "IAT_LiteraryDevices_Book_RadioEtiquette",
            "IAT_LiteraryDevices_Book_BanditryGuide",
            "IAT_LiteraryDevices_Book_NavigationProtocols",
            "IAT_LiteraryDevices_Book_ZombieSurvivalGuide",
        };
    };
    class IAT_LiteraryDevices_HandHeldTablet_Archive2 : IAT_LiteraryDevices_HandHeldTablet_Colorbase
    {
        scope = 2;
        displayName = "Tablet - Archive 2";
        booksInArchive[] =
        {
            "BookBible",
            "BookTheWarOfTheWorlds",
            "BookAroundTheWorldIn80Days",
            "BookCrimeAndPunishment",
            "BookTheMetamorphosis",
            "BookTheRaven",
            "BookTheArtOfWar",
            "BookRobinsonCrusoe",
            "BookRussian",
            "BookRussianCheatSheet",
        };
    };

};