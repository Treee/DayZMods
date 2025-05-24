modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );
        pType.AddItemInHandsProfileIK("IAT_Bear_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/TeddyBear.anm");

    };

    // override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    // {
    //     super.RegisterTwoHanded( pType, pBehavior );

    //     //==================================================== BLADE WEAPONS
    //     pType.AddItemInHandsProfileIK("IAT_Gramaphone_Colorbase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_sword.asi", pBehavior,	"dz/anims/anm/player/ik/two_handed/medieval_sword.anm");
    // }
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy( pType, pBehavior );

        //==================================================== BLADE WEAPONS
        pType.AddItemInHandsProfileIK("IAT_Gramaphone_Colorbase", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/sea_chest.anm");
    }
};