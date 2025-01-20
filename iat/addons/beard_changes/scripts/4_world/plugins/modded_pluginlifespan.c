modded class PluginLifespan
{
	ref protected TStringArray m_BeardTypes = {};
  	protected static const int LIFESPAN_MAX = 2880; // 240; // default value in minutes when player achieved maximum age in order to have full beard

	override protected void SetPlayerLifespanLevel( PlayerBase player, LifespanLevel level )
	{
		super.SetPlayerLifespanLevel(player, level);
		PopulateBeardsInList(level.GetLevel());
	}

	TStringArray GetBeards()
	{
		return m_BeardTypes;
	}

	void PopulateBeardsInList(float beardLifeTime)
	{
		m_BeardTypes.Clear();
		TStringArray m_OrderedBeards = GetOrderedBeardList();
		TStringArray m_BeardColors = GetBeardColorsAvailable();
		int m_TotalBeardTypes = m_OrderedBeards.Count();
		int indexOffset;
		string beardType;
		// check all the beards if they can be added
		for (int i = 0; i < m_TotalBeardTypes; i++;)
		{
			// we want interval to "start" above 0 so we need to modify the index by 1
			indexOffset = i / 3;
			// if the player beard is above this category, add the beard type
			if (beardLifeTime > (indexOffset))
			{
				// get the beard type template
				beardType = m_OrderedBeards.Get(i);
				// foreach color of the beard
				foreach(string beardColor : m_BeardColors)
				{	// add that beard to the list
					m_BeardTypes.Insert(string.Format("%1_%2", beardType, beardColor));
				}
			}
			else // else short circuit and break from the loop
				break;
		}
	}

	TStringArray GetBeardColorsAvailable()
	{
		return {
			"Black",
			"Brown",
			"Grey",
		};
	}

	TStringArray GetOrderedBeardList()
	{
		return {
			"ALV_Moustache2",
			"ALV_Moustache3",
			"ALV_Moustache1",
			"ALV_Goatee2",
			"ALV_Goatee1",
			"ALV_Beard3",
			"ALV_Beard6",
			"ALV_Beard1",
			"ALV_Beard2",
			"ALV_Beard4",
		};
	}
};