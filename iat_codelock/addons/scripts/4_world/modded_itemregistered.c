modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );

        //==================================================== BLADE WEAPONS
        pType.AddItemInHandsProfileIK("IAT_RaidHacksaw_Colorbase", "dz/anims/workspaces/player/player_main/props/player_main_1h_hacksaw.asi", pBehavior, "dz/anims/anm/player/ik/gear/hacksaw.anm");
    }
};