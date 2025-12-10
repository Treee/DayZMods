class IAT_CodelockRaidTool
{
	protected string m_ItemName; // the name of the item that is a raid tool
	protected float m_DamagePerUse; // the damage per use of the raid tool
	protected int m_CodelockDamagePerUse; // the damage per use of the codelock
	protected int m_TimePerDamage; // the time it takes to do damage with the raid tool
	protected bool m_DeleteLockOnRaid;// delete the codelock on raid

	void IAT_CodelockRaidTool(string itemName, float damagePerUse, int codelockDamagePerUse, int timePerDamage, bool deleteLockOnRaid = true)
	{
		m_ItemName = itemName;
		m_DamagePerUse = damagePerUse;
		m_CodelockDamagePerUse = codelockDamagePerUse;
		m_TimePerDamage = timePerDamage;
		m_DeleteLockOnRaid = deleteLockOnRaid;
	}

	// ========================================================= GETTERS & SETTERS
	string GetItemName()
	{
		return m_ItemName;
	}
	string GetItemNameLower()
	{
		string temp = m_ItemName;
		temp.ToLower();
		return temp;
	}
	float GetDamagePerUse()
	{
		return m_DamagePerUse;
	}
	int GetCodelockDamagePerUse()
	{
		return m_CodelockDamagePerUse;
	}
	int GetTimePerDamage()
	{
		return m_TimePerDamage;
	}
	bool GetDeleteLockOnRaid()
	{
		return m_DeleteLockOnRaid;
	}

	void SetItemName(string itemName)
	{
		m_ItemName = itemName;
	}
	void SetDamagePerUse(float damagePerUse)
	{
		m_DamagePerUse = damagePerUse;
	}
	void SetCodelockDamagePerUse(int codelockDamagePerUse)
	{
		m_CodelockDamagePerUse = codelockDamagePerUse;
	}
	void SetTimePerDamage(int timePerDamage)
	{
		m_TimePerDamage = timePerDamage;
	}
	void SetDeleteLockOnRaid(bool deleteLockOnRaid)
	{
		m_DeleteLockOnRaid = deleteLockOnRaid;
	}

	// ================================================================================== HELPERS
	bool MatchesClassName(string itemName)
	{
		// direct comparison
		if (m_ItemName == itemName)
			return true;

		string temp = m_ItemName;
		temp.ToLower();
		// this raid tool to lower case comparison
		if (temp == itemName)
			return true;
		// both items names to lower case comparison\
		itemName.ToLower();
		if (temp == itemName)
			return true;

		return false;
	}

	// for some reason my approach to use item.IsInherited(toolConfig.GetItemNameType())
	// isnt working so we are using g_Game.IsKindOf(type, parent) to check inheritance.
	// figure out why
	typename GetItemNameType()
	{
		// return the type of the item name
		return m_ItemName.ToType();
	}

	void PrettyPrint()
	{
		Print("--[IAT_CodelockRaidTool BEGIN]");
		PrintFormat("--m_ItemName: %1", m_ItemName);
		PrintFormat("--m_DamagePerUse: %1", m_DamagePerUse);
		PrintFormat("--m_CodelockDamagePerUse: %1", m_CodelockDamagePerUse);
		PrintFormat("--m_TimePerDamage: %1", m_TimePerDamage);
		PrintFormat("--m_DeleteLockOnRaid: %1", m_DeleteLockOnRaid);
		Print("--[IAT_CodelockRaidTool END]");
	}
};