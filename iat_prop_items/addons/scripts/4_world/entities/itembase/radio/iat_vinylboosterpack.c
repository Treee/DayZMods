class IAT_VinylBoosterPack_ColorBase extends ItemBase
{
	protected int m_TotalCardsToCreate = 0;
	// ============================================= VANILLA OVERRIDE
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionOpenVinylBoosterPack);
	}

	// ============================================= CUSTOM CODE
	void OpenBoosterPack()
	{
		// for each card to make
		for (int i = 0; i < m_TotalCardsToCreate; i++)
		{
			CreateCard(GetRandomCardFromBoosterSet());
		}
	}
	void CreateCard(string cardName)
	{
		GetGame().CreateObjectEx(cardName, GetPosition(), ECE_SETUP|ECE_PLACE_ON_SURFACE|ECE_NOLIFETIME|ECE_DYNAMIC_PERSISTENCY);
	}
	string GetRandomCardFromBoosterSet()
	{
		return GetSetCards().GetRandomElement();
	}
	TStringArray GetSetCards()
	{
		return {};
	}
};

class IAT_VinylBoosterPack_PlayableVinylCover extends IAT_VinylBoosterPack_ColorBase
{
	void IAT_VinylBoosterPack_PlayableVinylCover()
	{
		m_TotalCardsToCreate = 1;
	}
	// just randomly pick one of the 54 cards (jokers included)
	override TStringArray GetSetCards()
	{
		return {
			"IAT_PlayableVinylCover_ABetterDay",
			"IAT_PlayableVinylCover_ChantsOfTheWild",
			"IAT_PlayableVinylCover_ForgedInTheFire",
			"IAT_PlayableVinylCover_HerosFight",
			"IAT_PlayableVinylCover_HerosRest",
			"IAT_PlayableVinylCover_IntoTheMaw",
			"IAT_PlayableVinylCover_RustAndReverie",
			"IAT_PlayableVinylCover_SlowRoll",
			"IAT_PlayableVinylCover_Subterfuge",
			"IAT_PlayableVinylCover_VelvetNights",
			"IAT_PlayableVinylCover_VictoryDance",
			"IAT_PlayableVinylCover_VortexOfTheDamned",
		};
	}
};