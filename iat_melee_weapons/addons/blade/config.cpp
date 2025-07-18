class CfgPatches
{
    class IAT_Melee_Weapons_Blade
    {
        requiredAddons[] = { "DZ_Weapons_Melee", "DZ_Weapons_Melee_Blade" };
    };
};

class CfgAmmo
{
    class MeleeSlash;

    class IAT_MeleeSlash_1HSword : MeleeSlash
    {
        class DamageApplied
        {
            type = "Melee";
            class Health
            {
                damage = 20;
            };
            class Blood
            {
                damage = 120;
            };
            class Shock
            {
                damage = 0;
            };
        };
    };
    class IAT_MeleeSlash_1HSwordHeavy : IAT_MeleeSlash_1HSword {};
    class IAT_MeleeSlash_2HSword : MeleeSlash
    {
        class DamageApplied
        {
            type = "Melee";
            class Health
            {
                damage = 35;
            };
            class Blood
            {
                damage = 150;
            };
            class Shock
            {
                damage = 2;
            };
        };
    };
    class IAT_MeleeSlash_2HSwordHeavy : IAT_MeleeSlash_2HSword {};

    class IAT_MeleeSlash_2HSword_OneHitKill : MeleeSlash
    {
        class DamageApplied
        {
            type = "Melee";
            class Health
            {
                damage = 100;
            };
            class Blood
            {
                damage = 500;
            };
            class Shock
            {
                damage = 50;
            };
        };
    };
    class IAT_MeleeSlash_2HSword_OneHitKillHeavy : IAT_MeleeSlash_2HSword_OneHitKill {};

    class IAT_MeleeSlash_2HSword_Stun : MeleeSlash
    {
        class DamageApplied
        {
            type = "Melee";
            class Health
            {
                damage = 5;
            };
            class Blood
            {
                damage = 15;
            };
            class Shock
            {
                damage = 20;
            };
        };
    };
    class IAT_MeleeSlash_2HSword_StunHeavy : IAT_MeleeSlash_2HSword_Stun
    {
        class DamageApplied
        {
            type = "Melee";
            class Health
            {
                damage = 15;
            };
            class Blood
            {
                damage = 35;
            };
            class Shock
            {
                damage = 100;
            };
        };
    };
};

class CfgVehicles
{
    class Inventory_Base;

    class IAT_Melee_BerserkSword_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Antique Replica Berserk Sword";
        descriptionShort = "That thing was too big to be called a sword. Too big, too thick, too heavy, and too rough, it was more like a large hunk of iron.";
        model = "iat_melee_weapons\blade\iat_berserksword.p3d";
        rotationFlags = 12;
        inventorySlot[] =
        {
            "Shoulder",
            "Melee"
        };
        weight = 3600;
        itemSize[] = { 1,7 };
        itemBehaviour = 2;
        fragility = 0.02;
        openItemSpillRange[] = { 40,70 };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 50 };
        isMeleeWeapon = 1;
        hiddenSelections[] = { "zbytek", "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_berserksword_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_berserksword.rvmat" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0.05,-0.2,0 };//FB,UD,LR
                orientation[] = { 0,20,0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0.01,-0.2,0 };//FB,UD,LR
                orientation[] = { -0,-20,0 };//x,y,z
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_berserksword.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_berserksword.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_berserksword_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_berserksword_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_berserksword_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "IAT_MeleeSlash_2HSword";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 3.9;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 906;
                        sakhal_snow = 906;
                        sakhal_snow_forest = 906;
                        sakhal_grass_brown = 906;
                    };
                };
            };
        };
    };
    class IAT_Melee_BerserkSword_Basic : IAT_Melee_BerserkSword_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_berserksword_co.paa" };
    };
    class IAT_Melee_BerserkSword_Illusive : IAT_Melee_BerserkSword_Colorbase
    {
        scope = 2;
        displayName = "The Dragon Slayer";
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_berserksword_illusive_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_destruct.rvmat"}}
                    };
                };
            };
        };
    };
    class IAT_Melee_BerserkSword_theiliusiveman : IAT_Melee_BerserkSword_Colorbase
    {
        scope = 2;
        displayName = "The Dragon Slayer";
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_berserksword_illusive_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_berserksword_illusive.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_berserksword_illusive_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class IAT_Melee_JawBladeSword_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Jawblade Greatsword";
        descriptionShort = "A massive jawbone sharpened into a blade.";
        model = "iat_melee_weapons\blade\iat_jawblade.p3d";
        rotationFlags = 12;
        inventorySlot[] =
        {
            "Shoulder",
            "Melee"
        };
        weight = 3600;
        itemSize[] = { 1,7 };
        itemBehaviour = 2;
        fragility = 0.02;
        openItemSpillRange[] = { 40,70 };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 50 };
        isMeleeWeapon = 1;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_jawblade_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_jawblade.rvmat" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0.05,-0.2,0 };//FB,UD,LR
                orientation[] = { 0,20,0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0.01,-0.2,0 };//FB,UD,LR
                orientation[] = { -0,-20,0 };//x,y,z
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_jawblade.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_jawblade.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_jawblade_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_jawblade_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_jawblade_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "IAT_MeleeSlash_2HSword";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 3.9;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 906;
                        sakhal_snow = 906;
                        sakhal_snow_forest = 906;
                        sakhal_grass_brown = 906;
                    };
                };
            };
        };
    };
    class IAT_Melee_JawBladeSword_Basic : IAT_Melee_JawBladeSword_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_jawblade_co.paa" };
    };
    class IAT_Melee_JawBladeSword_Obamamama2580 : IAT_Melee_JawBladeSword_Colorbase
    {
        scope = 2;
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_jawblade_obamamama2580_co.paa" };
    };

    class IAT_Melee_FriedesScythe_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Serana's Scythe";
        descriptionShort = "A Scythe designed long ago by a Priestess, for dispatching the plague-addled as a mercy.";
        model = "iat_melee_weapons\blade\iat_serenascythe.p3d";
        rotationFlags = 12;
        inventorySlot[] =
        {
            "Shoulder",
            "Melee"
        };
        weight = 3600;
        itemSize[] = { 1,7 };
        itemBehaviour = 2;
        fragility = 0.02;
        openItemSpillRange[] = { 40,70 };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 50 };
        isMeleeWeapon = 1;
        hiddenSelections[] = { "zbytek", "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_scythe_co.paa", "iat_melee_weapons\blade\data\iat_scythe_pole_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_scythe.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole.rvmat" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0.05,-0.2,0 };//FB,UD,LR
                orientation[] = { 0,20,0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0.01,-0.2,0 };//FB,UD,LR
                orientation[] = { -0,-20,0 };//x,y,z
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_scythe.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_scythe.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_scythe_damage.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_scythe_damage.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_scythe_destruct.rvmat", "iat_melee_weapons\blade\data\iat_scythe_pole_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "IAT_MeleeSlash_2HSword";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 3.9;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 906;
                        sakhal_snow = 906;
                        sakhal_snow_forest = 906;
                        sakhal_grass_brown = 906;
                    };
                };
            };
        };
    };
    class IAT_Melee_FriedesScythe_Basic : IAT_Melee_FriedesScythe_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_scythe_co.paa", "iat_melee_weapons\blade\data\iat_scythe_pole_co.paa" };
    };
    class IAT_Melee_FriedesScythe_theamontiladoraven : IAT_Melee_FriedesScythe_Colorbase
    {
        scope = 2;
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_scythe_co.paa", "iat_melee_weapons\blade\data\iat_scythe_pole_co.paa" };
    };

    class IAT_Melee_GrinningBlade_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Grining Sword";
        descriptionShort = "A sword with many serrated edges almost as if grinning at its target.";
        model = "iat_melee_weapons\blade\iat_grinningblade.p3d";
        debug_ItemCategory = 2;
        animClass = "Knife";
        RestrainUnlockType = 1;
        repairableWithKits[] = { 4 };
        repairCosts[] = { 12 };
        inventorySlot[] = { "Backpack_1" };
        rotationFlags = 17;
        canSkinBodies = 1;
        weight = 1500;
        itemSize[] = { 1, 4 };
        lootTag[] = { "Work", "Forester", "Hunting", "Farm" };
        lootCategory = "Tools";
        itemInfo[] = { "Knife" };
        openItemSpillRange[] = { 10, 20 };
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_grinningblade_co.paa" };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                    healthLevels[] =
                    {
                        {1, {"iat_melee_weapons\blade\data\iat_grinningblade.rvmat"}},
                        {0.7, {"iat_melee_weapons\blade\data\iat_grinningblade.rvmat"}},
                        {0.5, {"iat_melee_weapons\blade\data\iat_grinningblade_damage.rvmat"}},
                        {0.3, {"iat_melee_weapons\blade\data\iat_grinningblade_damage.rvmat"}},
                        {0, {"iat_melee_weapons\blade\data\iat_grinningblade_destruct.rvmat"}}
                    };
                };
            };
        };
        isMeleeWeapon = 1;
        suicideAnim = "onehanded";
        class MeleeModes
        {
            class Default
            {
                ammo = "MeleeSharpLight_3";
                range = 1.4;
            };
            class Heavy
            {
                ammo = "MeleeSharpHeavy_3";
                range = 1.4;
            };
            class Sprint
            {
                ammo = "MeleeSharpHeavy_3";
                range = 3.3;
            };
        };
        soundImpactType = "metal";
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 907;
                        sakhal_snow = 907;
                        sakhal_snow_forest = 907;
                        sakhal_grass_brown = 907;
                    };
                };
            };
        };
    };
    class IAT_Melee_GrinningBlade_Basic : IAT_Melee_GrinningBlade_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_grinningblade_co.paa" };
    };
    class IAT_Melee_GrinningBlade_itsb14nk : IAT_Melee_GrinningBlade_Colorbase
    {
        scope = 2;
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_grinningblade_itsb14nk_co.paa" };
    };

    class IAT_Melee_ReaperScythe_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Reaper Scythe";
        descriptionShort = "A scythe designed for harvesting tall grains.";
        model = "iat_melee_weapons\blade\iat_reaperscythe.p3d";
        rotationFlags = 12;
        inventorySlot[] = { "Shoulder", "Melee" };
        weight = 3600;
        itemSize[] = { 1,7 };
        itemBehaviour = 2;
        fragility = 0.02;
        openItemSpillRange[] = { 40,70 };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 50 };
        isMeleeWeapon = 1;
        hiddenSelections[] = { "zbytek", "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_reaperscythe_co.paa", "iat_melee_weapons\blade\data\iat_reaperscythe_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_reaperscythe.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole.rvmat" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0.05,-0.2,0 };//FB,UD,LR
                orientation[] = { 0,20,0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0.01,-0.2,0 };//FB,UD,LR
                orientation[] = { -0,-20,0 };//x,y,z
            };
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_reaperscythe.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_reaperscythe.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_reaperscythe_damage.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_reaperscythe_damage.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_reaperscythe_destruct.rvmat", "iat_melee_weapons\blade\data\iat_reaperscythepole_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "IAT_MeleeSlash_2HSword";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 3.9;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 906;
                        sakhal_snow = 906;
                        sakhal_snow_forest = 906;
                        sakhal_grass_brown = 906;
                    };
                };
            };
        };
    };
    class IAT_Melee_ReaperScythe_Basic : IAT_Melee_ReaperScythe_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_reaperscythe_co.paa", "iat_melee_weapons\blade\data\iat_reaperscythe_co.paa" };
    };
    class IAT_Melee_ReaperScythe_legacylives : IAT_Melee_ReaperScythe_Colorbase
    {
        scope = 2;
        TradeClassName = "Sword";
        hiddenSelections[] = { "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_reaperscythe_legacylives_co.paa" };
    };

    class IAT_Melee_Glaive_Colorbase : Inventory_Base
    {
        scope = 0;
        displayName = "Glaive";
        descriptionShort = "A long reaching weapon with a sturdy handle and sharp blade.";
        model = "iat_melee_weapons\blade\iat_glaive.p3d";
        rotationFlags = 12;
        inventorySlot[] = { "Shoulder", "Melee" };
        weight = 3600;
        itemSize[] = { 1,7 };
        itemBehaviour = 2;
        fragility = 0.02;
        openItemSpillRange[] = { 40,70 };
        repairableWithKits[] = { 4 };
        repairCosts[] = { 50 };
        isMeleeWeapon = 1;
        hiddenSelections[] = { "zbytek", "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_glaive_co.paa", "iat_melee_weapons\blade\data\iat_glaive_co.paa" };
        hiddenSelectionsMaterials[] = { "iat_melee_weapons\blade\data\iat_glaive_blade.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole.rvmat" };
        class InventorySlotsOffsets
        {
            class Shoulder
            {
                position[] = { 0.05,-0.2,0 };//FB,UD,LR
                orientation[] = { 0,20,0 };//x,y,z
            };
            class Melee
            {
                position[] = { 0.01,-0.2,0 };//FB,UD,LR
                orientation[] = { -0,-20,0 };//x,y,z
            };
        };

        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 750;
                    healthLevels[] =
                    {
                        {1.0, { "iat_melee_weapons\blade\data\iat_glaive_blade.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole.rvmat"}},
                        {0.69999999, { "iat_melee_weapons\blade\data\iat_glaive_blade.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole.rvmat"}},
                        {0.5, { "iat_melee_weapons\blade\data\iat_glaive_blade_damage.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole_damage.rvmat"}},
                        {0.30000001, { "iat_melee_weapons\blade\data\iat_glaive_blade_damage.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole_damage.rvmat"}},
                        {0.0, { "iat_melee_weapons\blade\data\iat_glaive_blade_destruct.rvmat", "iat_melee_weapons\blade\data\iat_glaive_pole_destruct.rvmat"}}
                    };
                };
            };
        };
        class MeleeModes
        {
            class Default
            {
                ammo = "IAT_MeleeSlash_2HSword";
                range = 1.8;
            };
            class Heavy
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 1.8;
            };
            class Sprint
            {
                ammo = "IAT_MeleeSlash_2HSwordHeavy";
                range = 3.9;
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class animalSkinning_in
                {
                    soundSet = "animalSkinning_in_SoundSet";
                    id = 516;
                };
                class animalSkinning
                {
                    soundSet = "animalSkinning_SoundSet";
                    id = 517;
                };
                class animalSkinning_out
                {
                    soundSet = "animalSkinning_out_SoundSet";
                    id = 518;
                };
                class CutTies_end
                {
                    soundSet = "CutTies_end_SoundSet";
                    id = 519;
                };
                class CutTies_loop
                {
                    soundSet = "CutTies_loop_SoundSet";
                    id = 520;
                };
                class shaving_knife_clean
                {
                    soundSet = "shaving_knife_clean_SoundSet";
                    id = 600;
                };
                class shaving_knife1
                {
                    soundSet = "shaving_knife1_SoundSet";
                    id = 601;
                };
                class shaving_knife2
                {
                    soundSet = "shaving_knife2_SoundSet";
                    id = 602;
                };
                class shaving_knife3
                {
                    soundSet = "shaving_knife3_SoundSet";
                    id = 603;
                };
                class shaving_knife4
                {
                    soundSet = "shaving_knife4_SoundSet";
                    id = 604;
                };
                class shaving_knife5
                {
                    soundSet = "shaving_knife5_SoundSet";
                    id = 605;
                };
                class shaving_knife6
                {
                    soundSet = "shaving_knife6_SoundSet";
                    id = 606;
                };
                class shaving_knife7
                {
                    soundSet = "shaving_knife7_SoundSet";
                    id = 607;
                };
                class shaving_knife8
                {
                    soundSet = "shaving_knife8_SoundSet";
                    id = 608;
                };
                class shaving_knife9
                {
                    soundSet = "shaving_knife9_SoundSet";
                    id = 609;
                };
                class shaving_knife10
                {
                    soundSet = "shaving_knife10_SoundSet";
                    id = 610;
                };
                class shaving_knife11
                {
                    soundSet = "shaving_knife11_SoundSet";
                    id = 611;
                };
                class shaving_knife12
                {
                    soundSet = "shaving_knife12_SoundSet";
                    id = 612;
                };
                class shaving_knife13
                {
                    soundSet = "shaving_knife13_SoundSet";
                    id = 613;
                };
                class shaving_knife14
                {
                    soundSet = "shaving_knife14_SoundSet";
                    id = 614;
                };
                class shaving_knife15
                {
                    soundSet = "shaving_knife15_SoundSet";
                    id = 615;
                };
                class shaving_knife16
                {
                    soundSet = "shaving_knife16_SoundSet";
                    id = 616;
                };
                class shaving_knife17
                {
                    soundSet = "shaving_knife17_SoundSet";
                    id = 617;
                };
                class shaving_knife18
                {
                    soundSet = "shaving_knife18_SoundSet";
                    id = 618;
                };
                class shaving_knife19
                {
                    soundSet = "shaving_knife19_SoundSet";
                    id = 619;
                };
                class shaving_knife20
                {
                    soundSet = "shaving_knife20_SoundSet";
                    id = 620;
                };
                class shaving_knife21
                {
                    soundSet = "shaving_knife21_SoundSet";
                    id = 621;
                };
                class pickup_light
                {
                    soundSet = "hatchet_pickup_light_SoundSet";
                    id = 796;
                };
                class pickup
                {
                    soundSet = "hatchet_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "woodaxe_drop_SoundSet";
                    id = 898;
                };
                class FirefighterAxe_loop_SoundSet
                {
                    soundSet = "FirefighterAxe_loop_SoundSet";
                    id = 1121;
                };
                class FirefighterAxe_end_SoundSet
                {
                    soundSet = "FirefighterAxe_end_SoundSet";
                    id = 1122;
                };
            };
            class Sound
            {
                class SurfaceDig
                {
                    class DigPrimary
                    {
                        default = 906;
                        sakhal_snow = 906;
                        sakhal_snow_forest = 906;
                        sakhal_grass_brown = 906;
                    };
                };
            };
        };
    };
    class IAT_Melee_Glaive_Basic : IAT_Melee_Glaive_Colorbase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_glaive_co.paa", "iat_melee_weapons\blade\data\iat_glaive_co.paa" };
    };
    class IAT_Melee_Glaive_autumn2187 : IAT_Melee_Glaive_Colorbase
    {
        scope = 2;
        TradeClassName = "Sword";
        hiddenSelections[] = { "zbytek", "handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_glaive_autumn2187_co.paa", "iat_melee_weapons\blade\data\iat_glaive_autumn2187_co.paa" };
    };
};