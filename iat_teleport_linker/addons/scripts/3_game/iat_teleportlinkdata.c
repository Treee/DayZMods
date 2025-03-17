class IAT_TeleportLinkData
{
	protected string m_TeleportClassName;
	protected vector m_TeleportAnchorPosition;
	protected ref TVectorArray m_TeleportDestinations;

	// protected int m_TeleportKeyCardRequirement;
	// item damage per use
	// teleport radius size (send group of players)

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

	bool TeleportExists(string className, vector position)
	{
		// PrintFormat("[IAT_TeleportLinkData] Checking existence of %1 against %2 at actual position %3 verses expected %4.", m_TeleportClassName, className, m_TeleportAnchorPosition, position);
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

	TVectorArray GetTeleporterDestinations()
	{
		return m_TeleportDestinations;
	}

	vector GetTeleporterDestination()
	{
		return m_TeleportDestinations.GetRandomElement();
	}

};