modded class ModItemRegisterCallbacks
{
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded( pType, pBehavior );

        //====================================================
		pType.AddItemInHandsProfileIK("IAT_LootBox_Small_ColorBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/Cauldron.anm");
		pType.AddItemInHandsProfileIK("IAT_LootBox_Medium_ColorBase", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
		pType.AddItemInHandsProfileIK("IAT_LootBox_Large_ColorBase", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/vehicles/BatteryTruck.anm");
    }
};