modded class BrokenLegsMdfr
{
	override void OnDeactivate(PlayerBase player)
	{
		super.OnDeactivate(player);
		if ( player.IsWearingSplint() )
		{
			// remove our leg cast if wearing a split and leg is healed
			MiscGameplayFunctions.IAT_RemoveSplint(player); //Remove splint when leg is healed
		}
	}

};