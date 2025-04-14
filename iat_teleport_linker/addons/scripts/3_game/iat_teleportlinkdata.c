class IAT_TeleportLinkData
{
	protected string m_TeleportClassName;
	protected vector m_TeleportAnchorPosition;
	protected ref TVectorArray m_TeleportDestinations;

	protected string m_TeleportItemInHandsRequirement;
	protected float m_TeleportItemDamagePerUse;
	protected float m_TeleportRadius;

	// CONSTRUCTOR
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

	bool HasTeleportItemRequirement()
	{
		if (GetTeleportItemInHandsRequirementName() == "")
			return false;

		return true;
	}

	bool IsHoldingCorrectTeleportItemRequirement(string itemName)
	{
		// copy variable for tolower formatting
		string itemRequirement = m_TeleportItemInHandsRequirement;
		itemRequirement.ToLower();
		// get item in hands class name and tolower formatting
		itemName.ToLower();

		// if item in hands is an exact match; short circuit
		if (itemRequirement == itemName)
			return true;

		return false;
	}

	bool HasRequiredHealth(int itemHealthLevel)
	{
		return itemHealthLevel < GameConstants.STATE_RUINED;
	}

	string GetTeleportItemInHandsRequirementName()
	{
		if (m_TeleportItemInHandsRequirement)
			return m_TeleportItemInHandsRequirement;
		return "";
	}

	float GetTeleportItemDamagePerUse()
	{
		return m_TeleportItemDamagePerUse;
	}

	bool HasTeleportRadius()
	{
		if (GetTeleportRadius() == 0)
			return false;
		return true;
	}

	float GetTeleportRadius()
	{
		if (m_TeleportRadius)
			return m_TeleportRadius;
		return 0;
	}

};