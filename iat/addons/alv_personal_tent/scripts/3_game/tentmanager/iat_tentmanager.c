class IAT_TentManager
{
	protected ref map<string, int> m_IAT_TentOwners;

	void IAT_TentManager()
	{
		m_IAT_TentOwners = new map<string, int>;
	}

	bool IAT_HasDeployedTent(string playerId)
	{
		if (m_IAT_TentOwners.Contains(playerId))
		{
			return true;
		}
		return false;
	}

	void IAT_RegisterOwner(string id)
	{
		if (m_IAT_TentOwners.Contains(id))
		{
			PrintFormat("Existing tent deployed for id: %1. This should not of happened", id);
		}
		else
		{
			m_IAT_TentOwners.Insert(id, 1);
		}
	}
	void IAT_UnRegisterOwner(string id)
	{
		if (m_IAT_TentOwners.Contains(id))
		{
			m_IAT_TentOwners.Remove(id);
		}
	}
};