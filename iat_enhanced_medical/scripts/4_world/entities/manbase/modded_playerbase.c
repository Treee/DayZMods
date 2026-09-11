modded class PlayerBase
{
	protected ref IAT_PersistentWoundsServer m_IAT_PersistentWounds;

	override void Init()
	{
		super.Init();

		m_IAT_PersistentWounds = new IAT_PersistentWoundsServer(this);
	}

	bool IAT_IsWearingBandageOnBodyPart(string zoneName)
	{
		return false;
	}

	IAT_PersistentWoundsServer IAT_GetPersistentWounds()
	{
		return m_IAT_PersistentWounds;
	}
};