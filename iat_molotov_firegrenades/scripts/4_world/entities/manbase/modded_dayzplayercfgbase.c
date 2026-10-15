modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );

		pType.AddItemInHandsProfileIK("IAT_Molotov_Grenade_Incendiary", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/explosives/POX_grenade.anm");
		pType.AddItemInHandsProfileIK("IAT_Molotov_Grenade_Molotov", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/water_bottle.anm");
	}
};