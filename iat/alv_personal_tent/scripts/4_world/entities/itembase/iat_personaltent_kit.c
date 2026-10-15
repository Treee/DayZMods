class IAT_PersonalTent_Kit extends ALV_Kit_Base
{
	// this keeps the base Kit_Base behavior from creating the tent
	override bool UseDefaultKitPlacement()
	{
		return false;
	};

	// set the tent owner when this thing is placed
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{
		super.OnPlacementComplete( player, position, orientation );

		if(g_Game.IsDedicatedServer())
		{
			string newItemName = GetItemName();
			IAT_PersonalTent_ColorBase personalTent;
			if (Class.CastTo(personalTent, g_Game.CreateObjectEx(newItemName, position, ECE_PLACE_ON_SURFACE)))
			{
				personalTent.SetPosition(position);
				personalTent.SetOrientation(orientation);
				// Cast to player base to get access to the identity
				PlayerBase pb_Player;
				if (Class.CastTo(pb_Player, player))
				{
					personalTent.IAT_SetTentOwner(pb_Player.GetIdentity());
					personalTent.IAT_RegisterWithTentManager();
					pb_Player.TryFetchCanDeployPersonalTent(pb_Player.GetIdentity());
				}
			}
		}
		SetIsPlaceSound(true);
	};
};

class IAT_PersonalTent_Canvas_kit extends IAT_PersonalTent_Kit{};