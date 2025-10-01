class IAT_TeleportLinker_Basic extends ItemBase
{
	protected bool m_HasAnchor = false;

	protected string m_AnchorTypeName = "";
	protected vector m_AnchorPosition = vector.Zero;

	void IAT_TeleportLinker_Basic()
	{
		RegisterNetSyncVariableBool("m_HasAnchor");
	}

	override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
    }

	override void SetActions()
	{
		super.SetActions();

		AddAction(IAT_ActionSetAnchorTeleporter);
		AddAction(IAT_ActionSetTeleportDestination);
		AddAction(IAT_ActionClearTeleportDestination);
	}

	void UpdateAnchorTeleporter()
	{
		GetDayZGame().IAT_AddNewTeleportAnchor(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition());
	}

	void UpdateTeleporterDestination(vector teleportDestination)
	{
		GetDayZGame().IAT_AddNewTeleportDestination(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition(), teleportDestination);
	}

	void ClearTeleporterDestinations()
	{
		GetDayZGame().IAT_ClearTeleporterDestinations(GetBaseTeleporterTypeName(), GetBaseTeleporterAnchorPosition());
		m_HasAnchor = false;
		SetSynchDirty();
	}

	bool HasAnchorTeleport()
	{
		return m_HasAnchor;
	}

	bool IsSameObject(Object other)
	{
		return m_AnchorTypeName == other.GetType();
	}
	// ======================================= SETTERS & GETTERS
	void SetBaseTeleporterAnchor(Object anchor)
	{
		if (GetGame().IsDedicatedServer())
		{
			m_HasAnchor = true;
			m_AnchorTypeName = anchor.GetType();
			m_AnchorPosition = anchor.GetPosition();
			SetSynchDirty();
		}
	}
	string GetBaseTeleporterTypeName()
	{
		return m_AnchorTypeName;
	}
	vector GetBaseTeleporterAnchorPosition()
	{
		return m_AnchorPosition;
	}
}