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

    class IAT_Melee_BerserkSword_ColorBase : Inventory_Base
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
        weight = 600;
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
                class pickUp_Light
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
                    soundset = "baseballbat_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_Melee_BerserkSword_Basic : IAT_Melee_BerserkSword_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_berserksword_co.paa" };
    };
    class IAT_Melee_BerserkSword_Illusive : IAT_Melee_BerserkSword_ColorBase
    {
        scope = 2;
        displayName = "The Dragon Slayer";
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

    class IAT_Melee_FriedesScythe_ColorBase : Inventory_Base
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
        weight = 600;
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
                class pickUp_Light
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
                    soundset = "baseballbat_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
    class IAT_Melee_FriedesScythe_Basic : IAT_Melee_FriedesScythe_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_scythe_co.paa", "iat_melee_weapons\blade\data\iat_scythe_pole_co.paa" };
    };
    class IAT_Melee_FriedesScythe_theamontiladoraven : IAT_Melee_FriedesScythe_ColorBase
    {
        scope = 2;
        hiddenSelections[] = { "zbytek","handle" };
        hiddenSelectionsTextures[] = { "iat_melee_weapons\blade\data\iat_scythe_co.paa", "iat_melee_weapons\blade\data\iat_scythe_pole_co.paa" };
    };
};