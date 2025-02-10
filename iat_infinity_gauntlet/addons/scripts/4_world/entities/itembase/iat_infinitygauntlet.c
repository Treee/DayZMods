class IAT_InfinityGauntlet_ColorBase extends Gloves_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(IAT_InfinityGauntlet_SnapAction);
	}

	bool HasAllStones()
	{
		return GetInventory().AttachmentCount() == 6;
	}

	void BalanceTheUniverse()
	{
		array<Man> players = new array<Man>();
		GetGame().GetPlayers(players);

		int numPlayersHalf = players.Count() / 2;

		foreach (Man p : players)
		{
			p.SetHealth(0);
		}
	}
};