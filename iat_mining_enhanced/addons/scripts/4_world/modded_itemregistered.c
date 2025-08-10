modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

		pType.AddItemInHandsProfileIK("IAT_AdminPickaxe", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_pickaxe.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/pickaxe.anm");
    }
};