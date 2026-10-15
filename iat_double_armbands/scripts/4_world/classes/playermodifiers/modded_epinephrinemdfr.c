modded class EpinephrineMdfr
{
	override bool DeactivateCondition(PlayerBase player)
	{
		// if event character, do not deactivate the effect
		if (player.IAT_IsEventPlayer())
		{
			return false;
		}
		return super.DeactivateCondition(player);
	}
};