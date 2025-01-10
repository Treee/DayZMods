modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );
        // SCROLLS
        pType.AddItemInHandsProfileIK("IAT_LiteraryDevices_Scroll_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/hammer_ik.anm");
        pType.AddItemInHandsProfileIK("IAT_LiteraryDevices_HandHeldTablet_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
    };
};