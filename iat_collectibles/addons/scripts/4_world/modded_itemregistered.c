modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded( pType, pBehavior );

        pType.AddItemInHandsProfileIK("IAT_Bear_ColorBase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/TeddyBear.anm");
        pType.AddItemInHandsProfileIK("IAT_CardDeck_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");
        pType.AddItemInHandsProfileIK("IAT_TarotCardDeck_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");
        pType.AddItemInHandsProfileIK("IAT_CollectibleDeck_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/sewing_kit.anm");

        pType.AddItemInHandsProfileIK("IAT_PlayingCard_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_TarotCard_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_CollectibleCard_Colorbase", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");

        pType.AddItemInHandsProfileIK("IAT_BoosterPack_Collectibles_SRP_BR", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_BoosterPack_PlayingCards", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_BoosterPack_TarotCards", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_BoosterPack_VinylCover", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
        pType.AddItemInHandsProfileIK("IAT_BoosterPack_VinylRecordArt", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/paper.anm");
    }

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        pType.AddItemInHandsProfileIK("IAT_VinylCover_ColorBase", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/beartrap_g.anm");
        pType.AddItemInHandsProfileIK("IAT_VinylRecord_ColorBase", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/beartrap_g.anm");
        pType.AddItemInHandsProfileIK("IAT_VinylRecordArt_ColorBase", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/beartrap_g.anm");

		pType.AddItemInHandsProfileIK("IAT_GunFrame_Pistol_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi",	pBehavior, "dz/anims/anm/player/ik/two_handed/fire_extinguisher.anm");
		pType.AddItemInHandsProfileIK("IAT_GunFrame_Rifle_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi",	pBehavior, "dz/anims/anm/player/ik/two_handed/fire_extinguisher.anm");

		pType.AddItemInHandsProfileIK("IAT_PictureFrame_Landscape_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi",	pBehavior, "dz/anims/anm/player/ik/two_handed/fire_extinguisher.anm");
		pType.AddItemInHandsProfileIK("IAT_PictureFrame_Portrait_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/fire_extinguisher.anm");
		pType.AddItemInHandsProfileIK("IAT_PictureFrame_Square_ColorBase", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/fire_extinguisher.anm");

        pType.AddItemInHandsProfileIK("IAT_BoosterPack_PictureFrames", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/wooden_crate.anm");
    }
};
