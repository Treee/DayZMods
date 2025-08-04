modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );

        //==================================================== BLADE WEAPONS
        pType.AddItemInHandsProfileIK("IAT_Melee_GrinningBlade_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/machete.anm");
        pType.AddItemInHandsProfileIK("IAT_Narsil_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", pBehavior, "dz/anims/anm/player/ik/gear/fangeknife.anm");
        pType.AddItemInHandsProfileIK("IAT_Katana_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/machete.anm");
        pType.AddItemInHandsProfileIK("IAT_KatanaSheathe_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/crowbar.anm");
    }

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

        //==================================================== BLADE WEAPONS
        pType.AddItemInHandsProfileIK("IAT_Melee_BerserkSword_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sword.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/medieval_sword.anm");
        pType.AddItemInHandsProfileIK("IAT_Melee_JawBladeSword_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sword.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/medieval_sword.anm");
        pType.AddItemInHandsProfileIK("IAT_Katana_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sword.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/medieval_sword.anm");
        pType.AddItemInHandsProfileIK("IAT_Melee_FriedesScythe_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_farminghoe.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/farming_hoe.anm");
        pType.AddItemInHandsProfileIK("IAT_Melee_ReaperScythe_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_farminghoe.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/farming_hoe.anm");
        pType.AddItemInHandsProfileIK("IAT_Melee_Glaive_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_farminghoe.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/farming_hoe.anm");
    }
};