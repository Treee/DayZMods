modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );

        pType.AddItemInHandsProfileIK("IAT_Bear_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/TeddyBear.anm");
        pType.AddItemInHandsProfileIK("IAT_FieldShovel_Colorbase", "dz/anims/workspaces/player/player_main/props/player_main_1h_handshovel.asi", pBehavior, "dz/anims/anm/player/ik/gear/CSLA_Field_Shovel.anm");
        pType.AddItemInHandsProfileIK("IAT_PlayingCard_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/bait_worm.anm");
        pType.AddItemInHandsProfileIK("IAT_CardDeck_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");
        pType.AddItemInHandsProfileIK("IAT_TarotCard_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/bait_worm.anm");
        pType.AddItemInHandsProfileIK("IAT_TarotCardDeck_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");
        pType.AddItemInHandsProfileIK("IAT_LegCast_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");

        pType.AddItemInHandsProfileIK("IAT_ModernKnightHelm_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/ballistic_helmet.anm");


    }

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

        //====================================================
        pType.AddItemInHandsProfileIK("IAT_IronHammer_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sledgehammer.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/sledge_hammer.anm");
    }

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy( pType, pBehavior );

        //====================================================
        pType.AddItemInHandsProfileIK("IAT_Gramaphone_Colorbase", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/sea_chest.anm");
    }
};