class IAT_TeleportLinkData
{
	protected string m_TeleportClassName;
	protected vector m_TeleportAnchorPosition;
	protected ref TVectorArray m_TeleportDestinations;

	void IAT_TeleportLinkData(string teleportName, vector position)
	{
		m_TeleportClassName = teleportName;
		m_TeleportAnchorPosition = position;
	}

	vector GetPosition()
	{
		return m_TeleportAnchorPosition;
	}

	bool IsTeleportAnchorObject(string otherClassName)
	{
		return m_TeleportClassName == otherClassName;
	}

	bool Exists(string className, vector position)
	{
		if (className == m_TeleportClassName && position == m_TeleportAnchorPosition)
			return true;
		return false;
	}

	void AddDestination(vector destination)
	{
		if (!m_TeleportDestinations)
		{
			m_TeleportDestinations = new TVectorArray;
		}
		m_TeleportDestinations.Insert(destination);
	}

	void ClearDestinations()
	{
		if (m_TeleportDestinations)
			m_TeleportDestinations.Clear();
	}

	TVectorArray GetTeleporterDestination()
	{
		return m_TeleportDestinations;
	}

};