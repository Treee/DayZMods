modded class ItemBase
{
	protected bool m_HasCorrosiveAgent = false;

	void ItemBase()
	{
		RegisterNetSyncVariableBool("m_HasCorrosiveAgent");
	}

	override void DeferredInit()
	{
		super.DeferredInit();

		if (GetGame().IsDedicatedServer())
		{
			if (ContainsAgent(IAT_CB_Agents.CORROSION))
			{
				SetCorrosiveAgents(true);
				SetSynchDirty();
			}
		}
	}

	// ensure it still happens
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}

	override void OnItemLocationChanged(EntityAI old_owner, EntityAI new_owner)
	{
		super.OnItemLocationChanged(old_owner, new_owner);
		if (GetGame().IsDedicatedServer())
		{
			if (new_owner && HasCorrosiveAgents())
			{
				TransmitCorrosionAgents(new_owner);
			}
		}
	}

	// when an item gets drenched, remove corrosion
	override void OnWetLevelChanged(EWetnessLevel newLevel, EWetnessLevel oldLevel)
	{
		super.OnWetLevelChanged(newLevel, oldLevel);

		if (GetGame().IsDedicatedServer())
		{
			if (HasCorrosiveAgents() && newLevel >= EWetnessLevel.WET || oldLevel >= EWetnessLevel.WET)
			{
				RemoveAgent(IAT_CB_Agents.CORROSION);
				SetCorrosiveAgents(false);
				SetSynchDirty();
			}
		}
	}

	void TransmitCorrosionAgents(EntityAI target)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		plugin.TransmitAgentsEx(this, target, AGT_INV_IN, 1, IAT_CB_Agents.CORROSION);
	}

	bool HasCorrosiveAgents()
	{
		return m_HasCorrosiveAgent;
	}

	// used by the server to flag the client it has agents. bandaid for now until a more advanced agent system is available
	void SetCorrosiveAgents(bool newState)
	{
		m_HasCorrosiveAgent = newState;
	}

};