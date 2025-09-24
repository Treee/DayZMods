class IAT_BoosterPack_ColorBase extends ItemBase
{
	protected int m_TotalCardsToCreate = 0;
	// ============================================= VANILLA OVERRIDE
	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionOpenBoosterPack);
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

}
class IAT_BoosterPack_PlayingCards extends IAT_BoosterPack_ColorBase
{
	void IAT_BoosterPack_PlayingCards()
	{
		m_TotalCardsToCreate = 8;
	}
	// just randomly pick one of the 54 cards (jokers included)
	override TStringArray GetSetCards()
	{
		return {
			"IAT_PlayingCard_A_H",
			"IAT_PlayingCard_2_H",
			"IAT_PlayingCard_3_H",
			"IAT_PlayingCard_4_H",
			"IAT_PlayingCard_5_H",
			"IAT_PlayingCard_6_H",
			"IAT_PlayingCard_7_H",
			"IAT_PlayingCard_8_H",
			"IAT_PlayingCard_9_H",
			"IAT_PlayingCard_10_H",
			"IAT_PlayingCard_J_H",
			"IAT_PlayingCard_Q_H",
			"IAT_PlayingCard_K_H",
			"IAT_PlayingCard_A_D",
			"IAT_PlayingCard_2_D",
			"IAT_PlayingCard_3_D",
			"IAT_PlayingCard_4_D",
			"IAT_PlayingCard_5_D",
			"IAT_PlayingCard_6_D",
			"IAT_PlayingCard_7_D",
			"IAT_PlayingCard_8_D",
			"IAT_PlayingCard_9_D",
			"IAT_PlayingCard_10_D",
			"IAT_PlayingCard_J_D",
			"IAT_PlayingCard_Q_D",
			"IAT_PlayingCard_K_D",
			"IAT_PlayingCard_A_S",
			"IAT_PlayingCard_2_S",
			"IAT_PlayingCard_3_S",
			"IAT_PlayingCard_4_S",
			"IAT_PlayingCard_5_S",
			"IAT_PlayingCard_6_S",
			"IAT_PlayingCard_7_S",
			"IAT_PlayingCard_8_S",
			"IAT_PlayingCard_9_S",
			"IAT_PlayingCard_10_S",
			"IAT_PlayingCard_J_S",
			"IAT_PlayingCard_Q_S",
			"IAT_PlayingCard_K_S",
			"IAT_PlayingCard_A_C",
			"IAT_PlayingCard_2_C",
			"IAT_PlayingCard_3_C",
			"IAT_PlayingCard_4_C",
			"IAT_PlayingCard_5_C",
			"IAT_PlayingCard_6_C",
			"IAT_PlayingCard_7_C",
			"IAT_PlayingCard_8_C",
			"IAT_PlayingCard_9_C",
			"IAT_PlayingCard_10_C",
			"IAT_PlayingCard_J_C",
			"IAT_PlayingCard_Q_C",
			"IAT_PlayingCard_K_C",
			"IAT_PlayingCard_Joker_1",
			"IAT_PlayingCard_Joker_2			",
		};
	}
};
class IAT_BoosterPack_TarotCards extends IAT_BoosterPack_ColorBase
{
	void IAT_BoosterPack_TarotCards()
	{
		m_TotalCardsToCreate = 10;
	}
	// just randomly pick one of the cards
	override TStringArray GetSetCards()
	{
		return {
			"IAT_TarotCard_C_1",
			"IAT_TarotCard_C_2",
			"IAT_TarotCard_C_3",
			"IAT_TarotCard_C_4",
			"IAT_TarotCard_C_5",
			"IAT_TarotCard_C_6",
			"IAT_TarotCard_C_7",
			"IAT_TarotCard_C_8",
			"IAT_TarotCard_C_9",
			"IAT_TarotCard_C_10",
			"IAT_TarotCard_C_11",
			"IAT_TarotCard_C_12",
			"IAT_TarotCard_C_13",
			"IAT_TarotCard_C_14",
			"IAT_TarotCard_W_1",
			"IAT_TarotCard_W_2",
			"IAT_TarotCard_W_3",
			"IAT_TarotCard_W_4",
			"IAT_TarotCard_W_5",
			"IAT_TarotCard_W_6",
			"IAT_TarotCard_W_7",
			"IAT_TarotCard_W_8",
			"IAT_TarotCard_W_9",
			"IAT_TarotCard_W_10",
			"IAT_TarotCard_W_11",
			"IAT_TarotCard_W_12",
			"IAT_TarotCard_W_13",
			"IAT_TarotCard_W_14",
			"IAT_TarotCard_P_1",
			"IAT_TarotCard_P_2",
			"IAT_TarotCard_P_3",
			"IAT_TarotCard_P_4",
			"IAT_TarotCard_P_5",
			"IAT_TarotCard_P_6",
			"IAT_TarotCard_P_7",
			"IAT_TarotCard_P_8",
			"IAT_TarotCard_P_9",
			"IAT_TarotCard_P_10",
			"IAT_TarotCard_P_11",
			"IAT_TarotCard_P_12",
			"IAT_TarotCard_P_13",
			"IAT_TarotCard_P_14",
			"IAT_TarotCard_S_1",
			"IAT_TarotCard_S_2",
			"IAT_TarotCard_S_3",
			"IAT_TarotCard_S_4",
			"IAT_TarotCard_S_5",
			"IAT_TarotCard_S_6",
			"IAT_TarotCard_S_7",
			"IAT_TarotCard_S_8",
			"IAT_TarotCard_S_9",
			"IAT_TarotCard_S_10",
			"IAT_TarotCard_S_11",
			"IAT_TarotCard_S_12",
			"IAT_TarotCard_S_13",
			"IAT_TarotCard_S_14",
			"IAT_TarotCard_MA_1",
			"IAT_TarotCard_MA_2",
			"IAT_TarotCard_MA_3",
			"IAT_TarotCard_MA_4",
			"IAT_TarotCard_MA_5",
			"IAT_TarotCard_MA_6",
			"IAT_TarotCard_MA_7",
			"IAT_TarotCard_MA_8",
			"IAT_TarotCard_MA_9",
			"IAT_TarotCard_MA_10",
			"IAT_TarotCard_MA_11",
			"IAT_TarotCard_MA_12",
			"IAT_TarotCard_MA_13",
			"IAT_TarotCard_MA_14",
		};
	}

};
class IAT_BoosterPack_Collectibles_SRP_BR extends IAT_BoosterPack_ColorBase
{
	void IAT_BoosterPack_Collectibles_SRP_BR()
	{
		m_TotalCardsToCreate = 15;
	}

	override void OpenBoosterPack()
	{
		TStringArray cardsToCreate = CreateBoosterSet();
		// for each card to make
		foreach (string cardName : cardsToCreate)
		{
			CreateCard(cardName);
		}
	}

	// we want some custom logic for these cards
	TStringArray CreateBoosterSet()
	{
		TStringArray booster = new TStringArray();

		float chance = Math.RandomFloat01();
		// 12.5% chance (one in eight) to get mythic
		if (chance < 0.125)
		{
			booster.Insert(GetRareMythics().GetRandomElement());
		}
		else
		{
			booster.Insert(GetRares().GetRandomElement());
		}
		// 3 uncommons
		booster.Insert(GetUncommons().GetRandomElement());
		booster.Insert(GetUncommons().GetRandomElement());
		booster.Insert(GetUncommons().GetRandomElement());

		// 9 commons
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());
		booster.Insert(GetCommons().GetRandomElement());

		chance = Math.RandomFloat01();
		// 33% chance for a "foil" card otherwise 1 more common
		if (chance < 0.33)
		{
			// foils are just chances at rares or uncommons for now
			chance = Math.RandomFloat01();
			if (chance < 0.001)
			{
				booster.Insert(GetRareMythics().GetRandomElement());
			}
			else if (chance < 0.01)
			{
				booster.Insert(GetRares().GetRandomElement());
			}
			else if (chance < 0.33)
			{
				booster.Insert(GetUncommons().GetRandomElement());
			}
			else
			{
				booster.Insert(GetCommons().GetRandomElement());
			}
		}
		else
		{
			booster.Insert(GetCommons().GetRandomElement());
		}
		// 1 basic land
		booster.Insert(GetBasicLands().GetRandomElement());

		return booster;
	}

	TStringArray GetRares()
	{
		return {
			"IAT_CollectibleCard_SRP_BR_16",
			"IAT_CollectibleCard_SRP_BR_17",
			"IAT_CollectibleCard_SRP_BR_18",
			"IAT_CollectibleCard_SRP_BR_36",
			"IAT_CollectibleCard_SRP_BR_37",
			"IAT_CollectibleCard_SRP_BR_38",
			"IAT_CollectibleCard_SRP_BR_56",
			"IAT_CollectibleCard_SRP_BR_57",
			"IAT_CollectibleCard_SRP_BR_58",
			"IAT_CollectibleCard_SRP_BR_76",
			"IAT_CollectibleCard_SRP_BR_77",
			"IAT_CollectibleCard_SRP_BR_78",
			"IAT_CollectibleCard_SRP_BR_81",
			"IAT_CollectibleCard_SRP_BR_84",
			"IAT_CollectibleCard_SRP_BR_85",
			"IAT_CollectibleCard_SRP_BR_90",
			"IAT_CollectibleCard_SRP_BR_94",
			"IAT_CollectibleCard_SRP_BR_95",
			"IAT_CollectibleCard_SRP_BR_97",
			"IAT_CollectibleCard_SRP_BR_99",
			"IAT_CollectibleCard_SRP_BR_100",
			"IAT_CollectibleCard_SRP_BR_103",
			"IAT_CollectibleCard_SRP_BR_106",
			"IAT_CollectibleCard_SRP_BR_109",
			"IAT_CollectibleCard_SRP_BR_112",
			"IAT_CollectibleCard_SRP_BR_121",
			"IAT_CollectibleCard_SRP_BR_122",
			"IAT_CollectibleCard_SRP_BR_123",
			"IAT_CollectibleCard_SRP_BR_124",
			"IAT_CollectibleCard_SRP_BR_125",
			"IAT_CollectibleCard_SRP_BR_126",
			"IAT_CollectibleCard_SRP_BR_127",
			"IAT_CollectibleCard_SRP_BR_128",
			"IAT_CollectibleCard_SRP_BR_138",
			"IAT_CollectibleCard_SRP_BR_139",
			"IAT_CollectibleCard_SRP_BR_147",
			"IAT_CollectibleCard_SRP_BR_148",
			"IAT_CollectibleCard_SRP_BR_149",
			"IAT_CollectibleCard_SRP_BR_150",
		};
	}
	TStringArray GetRareMythics()
	{
		return {
			"IAT_CollectibleCard_SRP_BR_19",
			"IAT_CollectibleCard_SRP_BR_20",
			"IAT_CollectibleCard_SRP_BR_39",
			"IAT_CollectibleCard_SRP_BR_40",
			"IAT_CollectibleCard_SRP_BR_59",
			"IAT_CollectibleCard_SRP_BR_60",
			"IAT_CollectibleCard_SRP_BR_79",
			"IAT_CollectibleCard_SRP_BR_80",
			"IAT_CollectibleCard_SRP_BR_129",
			"IAT_CollectibleCard_SRP_BR_130",
			"IAT_CollectibleCard_SRP_BR_131",
			"IAT_CollectibleCard_SRP_BR_132",
			"IAT_CollectibleCard_SRP_BR_140",
		};
	}
	TStringArray GetUncommons()
	{
		return {
			"IAT_CollectibleCard_SRP_BR_11",
			"IAT_CollectibleCard_SRP_BR_12",
			"IAT_CollectibleCard_SRP_BR_13",
			"IAT_CollectibleCard_SRP_BR_14",
			"IAT_CollectibleCard_SRP_BR_15",
			"IAT_CollectibleCard_SRP_BR_31",
			"IAT_CollectibleCard_SRP_BR_32",
			"IAT_CollectibleCard_SRP_BR_33",
			"IAT_CollectibleCard_SRP_BR_34",
			"IAT_CollectibleCard_SRP_BR_35",
			"IAT_CollectibleCard_SRP_BR_51",
			"IAT_CollectibleCard_SRP_BR_52",
			"IAT_CollectibleCard_SRP_BR_53",
			"IAT_CollectibleCard_SRP_BR_54",
			"IAT_CollectibleCard_SRP_BR_55",
			"IAT_CollectibleCard_SRP_BR_71",
			"IAT_CollectibleCard_SRP_BR_72",
			"IAT_CollectibleCard_SRP_BR_73",
			"IAT_CollectibleCard_SRP_BR_74",
			"IAT_CollectibleCard_SRP_BR_75",
			"IAT_CollectibleCard_SRP_BR_82",
			"IAT_CollectibleCard_SRP_BR_83",
			"IAT_CollectibleCard_SRP_BR_86",
			"IAT_CollectibleCard_SRP_BR_87",
			"IAT_CollectibleCard_SRP_BR_88",
			"IAT_CollectibleCard_SRP_BR_89",
			"IAT_CollectibleCard_SRP_BR_91",
			"IAT_CollectibleCard_SRP_BR_92",
			"IAT_CollectibleCard_SRP_BR_93",
			"IAT_CollectibleCard_SRP_BR_96",
			"IAT_CollectibleCard_SRP_BR_98",
			"IAT_CollectibleCard_SRP_BR_102",
			"IAT_CollectibleCard_SRP_BR_105",
			"IAT_CollectibleCard_SRP_BR_108",
			"IAT_CollectibleCard_SRP_BR_111",
			"IAT_CollectibleCard_SRP_BR_113",
			"IAT_CollectibleCard_SRP_BR_114",
			"IAT_CollectibleCard_SRP_BR_115",
			"IAT_CollectibleCard_SRP_BR_116",
			"IAT_CollectibleCard_SRP_BR_117",
			"IAT_CollectibleCard_SRP_BR_118",
			"IAT_CollectibleCard_SRP_BR_119",
			"IAT_CollectibleCard_SRP_BR_120",
			"IAT_CollectibleCard_SRP_BR_133",
			"IAT_CollectibleCard_SRP_BR_134",
			"IAT_CollectibleCard_SRP_BR_135",
			"IAT_CollectibleCard_SRP_BR_136",
			"IAT_CollectibleCard_SRP_BR_137",
			"IAT_CollectibleCard_SRP_BR_141",
			"IAT_CollectibleCard_SRP_BR_142",
			"IAT_CollectibleCard_SRP_BR_143",
			"IAT_CollectibleCard_SRP_BR_144",
			"IAT_CollectibleCard_SRP_BR_145",
			"IAT_CollectibleCard_SRP_BR_146",
		};
	}
	TStringArray GetCommons()
	{
		return {
			"IAT_CollectibleCard_SRP_BR_1",
			"IAT_CollectibleCard_SRP_BR_2",
			"IAT_CollectibleCard_SRP_BR_3",
			"IAT_CollectibleCard_SRP_BR_4",
			"IAT_CollectibleCard_SRP_BR_5",
			"IAT_CollectibleCard_SRP_BR_6",
			"IAT_CollectibleCard_SRP_BR_7",
			"IAT_CollectibleCard_SRP_BR_8",
			"IAT_CollectibleCard_SRP_BR_9",
			"IAT_CollectibleCard_SRP_BR_10",
			"IAT_CollectibleCard_SRP_BR_21",
			"IAT_CollectibleCard_SRP_BR_22",
			"IAT_CollectibleCard_SRP_BR_23",
			"IAT_CollectibleCard_SRP_BR_24",
			"IAT_CollectibleCard_SRP_BR_25",
			"IAT_CollectibleCard_SRP_BR_26",
			"IAT_CollectibleCard_SRP_BR_27",
			"IAT_CollectibleCard_SRP_BR_28",
			"IAT_CollectibleCard_SRP_BR_29",
			"IAT_CollectibleCard_SRP_BR_30",
			"IAT_CollectibleCard_SRP_BR_41",
			"IAT_CollectibleCard_SRP_BR_42",
			"IAT_CollectibleCard_SRP_BR_43",
			"IAT_CollectibleCard_SRP_BR_44",
			"IAT_CollectibleCard_SRP_BR_45",
			"IAT_CollectibleCard_SRP_BR_46",
			"IAT_CollectibleCard_SRP_BR_47",
			"IAT_CollectibleCard_SRP_BR_48",
			"IAT_CollectibleCard_SRP_BR_49",
			"IAT_CollectibleCard_SRP_BR_50",
			"IAT_CollectibleCard_SRP_BR_61",
			"IAT_CollectibleCard_SRP_BR_62",
			"IAT_CollectibleCard_SRP_BR_63",
			"IAT_CollectibleCard_SRP_BR_64",
			"IAT_CollectibleCard_SRP_BR_65",
			"IAT_CollectibleCard_SRP_BR_66",
			"IAT_CollectibleCard_SRP_BR_67",
			"IAT_CollectibleCard_SRP_BR_68",
			"IAT_CollectibleCard_SRP_BR_69",
			"IAT_CollectibleCard_SRP_BR_70",
		};
	}
	TStringArray GetBasicLands()
	{
		return {
			"IAT_CollectibleCard_SRP_BR_101",
			"IAT_CollectibleCard_SRP_BR_104",
			"IAT_CollectibleCard_SRP_BR_107",
			"IAT_CollectibleCard_SRP_BR_110",
		};
	}
};