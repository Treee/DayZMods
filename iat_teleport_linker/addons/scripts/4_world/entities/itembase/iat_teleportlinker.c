class IAT_TeleportLinker_Basic extends ItemBase
{
	protected ref Object m_BaseTeleportAnchor;

	void IAT_TeleportLinker_Basic()
	{
		// this way other clients can interact with the hammer too if needed
		RegisterNetSyncVariableObject("m_BaseTeleportAnchor");
	}

	override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
    }

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionSetAnchorTeleporter);
	}

	void UpdateAnchorTeleporter()
	{
		IAT_TeleportLinkConfig config = GetDayZGame().GetIATTeleportLinkConfig();
		config.AddNewTeleportAnchor(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition());
	}

	void UpdateTeleporterDestination(vector teleportDestination)
	{
		IAT_TeleportLinkConfig config = GetDayZGame().GetIATTeleportLinkConfig();
		config.AddNewTeleportDestination(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition(), teleportDestination);
	}

	void ClearTeleporterDestinations()
	{
		IAT_TeleportLinkConfig config = GetDayZGame().GetIATTeleportLinkConfig();
		config.ClearTeleporterDestinations(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition());
	}

	bool HasAnchorTeleport()
	{
		return m_BaseTeleportAnchor != null;
	}

	bool IsSameObject(Object other)
	{
		return m_BaseTeleportAnchor == other;
	}
	// ======================================= SETTERS & GETTERS

	Object GetBaseTeleporterAnchor()
	{
		return m_BaseTeleportAnchor;
	}

	void SetBaseTeleporterAnchor(Object anchor)
	{
		m_BaseTeleportAnchor = anchor;
	}

	string GetBaseTeleporterTypeName()
	{
		if (m_BaseTeleportAnchor)
			return m_BaseTeleportAnchor.GetType();
		return "null";
	}

	vector GetBaseTeleporterAnchorPosition()
	{
		if (m_BaseTeleportAnchor)
			return m_BaseTeleportAnchor.GetPosition();
		return "0 0 0";
	}
}