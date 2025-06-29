modded class BrokenLegsMdfr
{
	override void OnDeactivate(PlayerBase player)
	{
		// do our stuff only if we need to
		if ( player.IAT_IsWearingSplint() )
		{
			MiscGameplayFunctions.IAT_RemoveSplint(player);
		}
		super.OnDeactivate(player);
	}
};