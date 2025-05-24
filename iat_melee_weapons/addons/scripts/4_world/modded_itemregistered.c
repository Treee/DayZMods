modded class ModItemRegisterCallbacks
{
    // override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    // {
    //     super.RegisterOneHanded( pType, pBehavior );
    // };

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

        //==================================================== BLADE WEAPONS
        pType.AddItemInHandsProfileIK("IAT_Melee_BerserkSword_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sword.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/medieval_sword.anm");
        pType.AddItemInHandsProfileIK("IAT_Melee_FriedesScythe_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_farminghoe.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/farming_hoe.anm");
    }
};