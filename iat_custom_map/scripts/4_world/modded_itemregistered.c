modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );
		// technically dont need this since we inherit from cherno map anyway but i like being explicit :O
        pType.AddItemInHandsProfileIK("IAT_CustomMap_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/Map_chernarus.anm");
    }
};