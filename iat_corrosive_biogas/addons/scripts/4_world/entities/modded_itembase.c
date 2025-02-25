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
			if (HasCorrosiveAgents())
			{
				PlayerBase player;
				if (Class.CastTo())
				PlayerBase pb_Player = PlayerBase.Cast(player);
				TransmitCorrosionAgents(pb_Player)
			}
		}
	}

	// override void OnInventoryEnter(Man player)
	// {
	// 	super.OnInventoryEnter(player);
	// 	if (GetGame().IsDedicatedServer())
	// 	{
	// 		if (HasCorrosiveAgents())
	// 		{
	// 			PlayerBase pb_Player = PlayerBase.Cast(player);
	// 			TransmitCorrosionAgents(pb_Player)
	// 		}
	// 	}
	// }

	void TransmitCorrosionAgents(PlayerBase player)
	{
		PluginTransmissionAgents plugin = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		return plugin.TransmitAgentsEx(this, player, AGT_INV_IN, 1, IAT_CB_Agents.CORROSION);
	}

	bool HasCorrosiveAgents()
	{
		if (GetGame().IsDedicatedServer())
		{
			return ContainsAgent(IAT_CB_Agents.CORROSION);
		}
		else
		{
			return m_HasCorrosiveAgent;
		}
	}

	// used by the server to flag the client it has agents. bandaid for now until a more advanced agent system is available
	void SetCorrosiveAgents(bool newState)
	{
		m_HasCorrosiveAgent = newState;
	}

};