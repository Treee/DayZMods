modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );
        pType.AddItemInHandsProfileIK("IAT_CarvedSymbol_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
    }
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

        pType.AddItemInHandsProfileIK("IAT_CarvedSymbol_Kit", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi",	pBehavior, "dz/anims/anm/player/ik/two_handed/firewood.anm");
    }
};